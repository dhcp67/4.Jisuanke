/*************************************************************************
	> File Name: p1598.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月17日 星期日 16时02分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main () {
    char poer[4][101] = {0}, A = 'A';
    int num[26] = {0}, len, i, j, cnt, max = 0;
    for (int i = 0; i < 4; i++) {
        gets(poer[i]);
    }
    for(i = 0; i < 4; i++) {
        len = strlen(poer[i]);
        for (j = 0; j < len; j++) {
            if (poer[i][j] == ' ') continue;
            num[poer[i][j] - 'A']++;
        }
    }
    for(i = 0; i < 26; i++) {
        if(max < num[i]) {
            max = num[i];
            cnt = i;
        }
    }
    printf("%d\n", max);
    for(i = 0; i < 26; i++) {
        num[i] = max - num[i];
    }
    for(j = 0; j < max; j++) {
        for(i = 0; i < 26; i++) {
            if(num[i] == 0) {
                printf("*\t");
            }else{
                printf("\t");
                num[i]--;
            }
        }
        if(i != 25) printf("\t");
        else printf("\n");
    }
    for (i = 0; i < 26; i++) {
        printf("%c\t", A);
        A = A + 1;
    }
    printf("\n");
    return 0;
}
