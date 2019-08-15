/*************************************************************************
	> File Name: test.c
	> Author: LiChun
	> Mail: 318082789@qq.com
	> Created Time: 2019年08月05日 星期一 12时03分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

typedef struct Stack{
	int *data;
    int size,top;
} Stack;

Stack *init(Stack *sta, int n) {
    sta = (Stack *)malloc(sizeof(Stack));
    sta->data = (int *)malloc(sizeof(int) * n);
    sta->size = n;
    sta->top = -1;
    return sta;
}

int empty(Stack *sta) {
    return sta->top < 0;
}

void push(Stack *sta, int val) {
    sta->top++;
    sta->data[sta->top] = val;
}

void pop(Stack *sta) {
    if (empty(sta)) {
        printf("error\n");
        return ;
    }
    sta->top--;
}

int top(Stack *sta) {
    return sta->data[sta->top];
}

void clear(Stack *sta) {
    free(sta->data);
    free(sta);
}

int main() {
	Stack *sta;
    sta = init(sta, MAX_N + 5);
    int n;
    int buff[MAX_N + 5] = {0};
    scanf("%d", &n);
	for (int i = 0; i < n; i++) {
        scanf("%d", &buff[i]);
    }
    int cnt = 1, atex = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        int tmp = buff[i];
		if (!empty(sta) && top(sta) == tmp) {
            printf("%d ", top(sta));
            pop(sta);
            ret++;
            if (empty(sta)) {
                push(sta, cnt);
                cnt++;
            }
        } else {
            while (cnt != tmp && cnt < n) {
                push(sta, cnt);
                cnt++;
            }
            if (cnt == tmp) {
                printf("%d ", cnt);
                cnt++;
                ret++;
            }
        }
    }
    printf("\n");
    if (ret >= n) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    clear(sta);
	return 0;
} 
