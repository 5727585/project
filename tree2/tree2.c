#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //만약 오른쪽 링크가 스레드이면 TRUE
} TreeNode;

TreeNode* find_successor(TreeNode* p)
{
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
		printf("%c ", q->data);// 데이터 출력
		q = find_successor(q); // 후속자 함수 호출
	} while (q);			// NULL이 아니면
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");

	return 0;
}

