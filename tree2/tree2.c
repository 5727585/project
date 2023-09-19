#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left, * right;
} TreeNode;

// ((((2+3)+(4*5))-(6/7))+9)

TreeNode n1 = { '2', NULL, NULL };
TreeNode n2 = { '3', NULL, NULL };
TreeNode n3 = { '+', &n1, &n2 };
TreeNode n4 = { '4', NULL, NULL };
TreeNode n5 = { '5', NULL, NULL };
TreeNode n6 = { '*', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode n8 = { '6', NULL, NULL };
TreeNode n9 = { '7', NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { '-', &n7, &n10 };
TreeNode n12 = { '9', NULL, NULL };
TreeNode n13 = { '+', &n11, &n12 };

TreeNode* exp = &n13;

// ���� ��� �Լ�
double evaluate(TreeNode* root)
{
    if (root == NULL)   return 0;
    if (root->left == NULL && root->right == NULL) {
        return atof(&root->data); // ���ڸ� ���ڷ� ��ȯ
    }
    else {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
        printf("%.2lf %c %.2lf�� ����մϴ�.\n", op1, root->data, op2);
        switch (root->data) {
        case '+':   return op1 + op2;
        case '-':   return op1 - op2;
        case '*':   return op1 * op2;
        case '/':   return op1 / op2;
        }
    }
    return 0;
}

//����� ������ ���ϴ� �Լ�
int get_node_count(TreeNode* node)
{
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + //root�� �ϳ��̹Ƿ� 1�� ���ϰ� ������
        get_node_count(node->right); //��ȸ�ϸ� ����� ������ ����
    return count;
}

int main(void)
{
    printf("������ ���� %.2lf�Դϴ�. \n\n", evaluate(exp));

    int nodecount = get_node_count(exp);
    printf("�� ��� ������ %d�Դϴ�. \n", nodecount);

    return 0;
}
