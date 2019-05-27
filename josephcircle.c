/*************************************************************************
	> File Name: josephcircle.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月24日 星期日 13时04分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

// 创建结点
typedef struct node{
    int num;
    struct node *next;
}Node;

// 创建环
Node *circle(int digit) {
    Node *tail, *ret, *head;
    head = (Node *)malloc(sizeof(Node));
    head->num = 1;
    tail = head;
    ret = head;
    for (int i = 2; i <= digit; i++) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->num = i;
//        printf("%d\n", temp->num);// 测试用
        ret->next = temp;   
        ret = ret->next;
    }
    tail = ret;
    tail->next = head;
//    printf("001\n");// test
    // 返回尾结点地址
    return tail;
}

void find (Node *temp_tail, int k, int m) {
    Node *p;
    for(int i = 1; i < k; i++) {
        temp_tail = temp_tail->next;
    }
    while(temp_tail->next != temp_tail) {
        p = temp_tail;
        for(int j = 0; j < m; j++) {
            temp_tail = p;
            p = p->next;
        }
        temp_tail->next = temp_tail->next->next;
        printf("%d ", p->num);
        free(p);
        p = NULL;

    }
    printf("%d", temp_tail->num);
    free(temp_tail);
}

int main() {
    int n, k, m;
    Node *temp;
    printf("输入人数，开始位置，报数数\n");
    scanf("%d%d%d", &n, &k, &m);
    temp = circle(n);// 调用函数，创建环
//    printf("temp->num");// test

    find(temp, k, m);// 调用函数，输出
    printf("\n");
    return 0;
}
