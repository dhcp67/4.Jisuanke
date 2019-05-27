/*************************************************************************
	> File Name: lianbiaojiegou.c
	> Author: lc
	> Mail: 
	> Created Time: 2019年03月23日 星期六 12时30分26秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int temp_number;
    struct node *next;
}Node;
Node *create_node(int number) {
    Node *temp_next;
    temp_next = (Node *)malloc(sizeof(Node));
    temp_next->temp_number = number;
    temp_next->next = NULL;
    return temp_next;
}
int main() {
    Node *head;
    int num[4];
    for(int i = 0; i < 4; i++) {
        scanf("%d", &num[i]);
    }
    head = create_node(num[0]);
    head->next = create_node(num[1]);
    head->next->next = create_node(num[2]);
    head->next->next->next = create_node(num[3]);
    printf("%d\n", head->temp_number);
    printf("%d\n", head->next->temp_number);
    printf("%d\n", head->next->next->temp_number);
    printf("%d\n", head->next->next->next->temp_number);
    return 0;
}
