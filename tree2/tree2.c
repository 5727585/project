#include <stdio.h>
# define TRUE 1
# define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    int is_thread; // 만약 오른쪽 링크가 스레드이면 TRUE
} TreeNode;

TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n1, &n2 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 8, NULL, NULL };
TreeNode n7 = { 10, NULL, NULL };
TreeNode n8 = { 11, NULL, NULL };
TreeNode n9 = { 9, &n7, &n8 };
TreeNode n10 = { 7, &n6, &n9 };
TreeNode n11 = { 1, &n5, &n10 };
TreeNode* root = &n11;

TreeNode* find_successor(TreeNode* p) {
    // q는 p의 오른쪽 포인터
    TreeNode* q = p->right;
    // 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
    if (q == NULL || p->is_thread == TRUE)
        return q;

    // 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode* t)
{
    TreeNode* q;
    q = t;
    while (q->left) q = q->left;// 가장 왼쪽 노드로 간다.
    do
    {
        printf("%c -> ", q->data);// 데이터 출력
        q = find_successor(q); // 후속자 함수 호출
    } while (q);			// NULL이 아니면
}

int main(void) {
    n1.right = &n3;
    n2.right = &n5;
    n4.right = &n11;
    n6.right = &n10;
    n7.right = &n9;

    thread_inorder(root);
    printf("\n");

    return 0;
}