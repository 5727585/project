#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


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

//링크 트리 구현
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

//배열 트리 구현
int array[16] = { 0,1,2,7,3,6,8,9,4,5,0,0,0,0,10,11 };

void array_preorder(int i) {
	if (i && array[i] != 0) {
		printf("[%d] ", array[i]);
		array_preorder(2 * i);  
		array_preorder(2 * i + 1); 
	}
}

void array_inorder(int i) {
	if (i && array[i] != 0) {
		array_inorder(2 * i);
		printf("[%d] ", array[i]);
		array_inorder(2 * i + 1);
	}
}

void array_postorder(int i) {
	if (i && array[i] != 0) {  
		array_postorder(2 * i);
		array_postorder(2 * i + 1);  
		printf("[%d] ", array[i]);  
	}
}


void  main()
{
	printf("Linked Tree\n");

	printf("전위 순회= ");
	preorder(root);
	printf("\n\n");

	printf("중위 순회= ");
	inorder(root);
	printf("\n\n");

	printf("후위 순회= ");
	postorder(root);
	printf("\n\n\n");

	printf("Array Tree\n");

	printf("전위 순회= ");
	array_preorder(1);
	printf("\n\n");

	printf("중위 순회= ");
	array_inorder(1);
	printf("\n\n");

	printf("후위 순회= ");
	array_postorder(1);
	printf("\n\n");

	return 0;
}