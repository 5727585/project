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

// 수식 계산 함수
double evaluate(TreeNode* root)
{
    if (root == NULL)   return 0;
    if (root->left == NULL && root->right == NULL) {
        return atof(&root->data); // 문자를 숫자로 변환
    }
    else {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
        printf("%.2lf %c %.2lf을 계산합니다.\n", op1, root->data, op2);
        switch (root->data) {
        case '+':   return op1 + op2;
        case '-':   return op1 - op2;
        case '*':   return op1 * op2;
        case '/':   return op1 / op2;
        }
    }
    return 0;
}

//노드의 개수를 구하는 함수
int get_node_count(TreeNode* node)
{
    int count = 0;
    if (node != NULL)
        count = 1 + get_node_count(node->left) + //root는 하나이므로 1를 더하고 시작함
        get_node_count(node->right); //순회하며 노드의 개수를 더함
    return count;
}

int main(void)
{
    printf("수식의 값은 %.2lf입니다. \n\n", evaluate(exp));

    int nodecount = get_node_count(exp);
    printf("총 노드 개수는 %d입니다. \n", nodecount);

    return 0;
}
