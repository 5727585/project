#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //���� ������ ��ũ�� �������̸� TRUE
} TreeNode;

TreeNode* find_successor(TreeNode* p)
{
	// q�� p�� ������ ������
	TreeNode* q = p->right;
	// ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if (q == NULL || p->is_thread == TRUE)
		return q;

	// ���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t)
{
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;// ���� ���� ���� ����.
	do
	{
		printf("%c ", q->data);// ������ ���
		q = find_successor(q); // �ļ��� �Լ� ȣ��
	} while (q);			// NULL�� �ƴϸ�
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
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");

	return 0;
}

