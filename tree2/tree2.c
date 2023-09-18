#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

int is_empty()
{
	return top == -1;
}

void inorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

void preorder_iter(TreeNode* root)
{
	push(root);
	while (!is_empty()) {
		root = pop();
		printf("[%d] ", root->data);

		if (root->right)
			push(root->right);
		if (root->left)
			push(root->left);
	}
}


void postorder_iter(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeNode* prev = NULL;
	do {
		while (root) {
			push(root);
			root = root->left;
		}

		while (root == NULL && top >= 0) {
			root = stack[top];
			if (root->right == NULL || root->right == prev) {
				printf("[%d] ", root->data);
				pop();
				prev = root;
				root = NULL;
			}
			else {
				root = root->right;
			}
		}
	} while (top >= 0);
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

	printf("전위 순회=");
	preorder_iter(root);
	printf("\n");

	printf("후위 순회=");
	postorder_iter(root);
	printf("\n");
	printf("\n");

	return 0;
}

