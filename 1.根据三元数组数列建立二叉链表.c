/*************************************************************************
	> File Name: 1.根据三元数组数列建立二叉链表.c
	> Author: LiChun
	> Mail: 318082789@qq.com
	> Created Time: 2019年08月07日 星期三 16时29分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *init(char val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->lchild = NULL;
    node->rchild = NULL;
    node->data = val;
    return node;
}

Node *build(Node *root, char *str) {
    if (str[0] == '^') {
        Node *node = init(str[1]);
    	return node;
    } else {
        if (root->data == str[0]) {
            if (str[2] == 'L') {
                root->lchild = init(str[1]);
            } else {
                root->rchild = init(str[1]);
            }
            return root;
        } else {
            if (root->lchild) {
                root->lchild = build(root->lchild, str);
            }
            if (root->rchild) {
                root->rchild = build(root->rchild, str);
            }
            return root;
        }
    }
}

void preorder(Node *node) {
    printf("%c", node->data);
    if (node->lchild) {
        printf("(");
        preorder(node->lchild);
        if (!node->rchild) {
            printf(")");
        } else {
            printf(",");
        }
    }
    if (node->rchild) {
        if (!node->lchild) {
            printf("(,");
        }
        preorder(node->rchild);
        printf(")");
    }
    return ;
}

void clear(Node *node) {
    if (node->lchild) {
        clear(node->lchild);
    }
    if (node->rchild) {
        clear(node->rchild);
    }
    clear(node);
}

int main() {
	char str[4] = {0};
	Node *root = NULL;
	while (1) {
        scanf("%s", str);
        if (str[1] == '^') break;
        root = build(root, str);
    }
    if (root) preorder(root);
    printf("\n");
    return 0;
}
