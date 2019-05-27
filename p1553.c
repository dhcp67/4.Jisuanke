/*************************************************************************
	> File Name: p1553.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月17日 星期日 19时42分18秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main () {
    char num[20];
    int left = 0, right = 0, i, j, len, n = 1, cnt = 0;
    long long digit;
    gets(num);
    len = strlen(num);
    for(i = 0; i < len; i++) {
        if(num[i] == '.' || num[i] == '/' || num[i] == '%') {
            cnt = i;
        }
    }
    if (!cnt) {
        for(i = len - 1; i >= 0; i--) {
            if(num[i] - '0' != 0) {
                left = 1;
                printf("%c", num[i]);
            }else if (left != 0) {
                printf("%c", num[i]);
            }
            if(i == 0 && left == 0) printf("0");
        }
    } else {
        for(i = cnt - 1; i >= 0; i--) {
            if (num[i] - '0' != 0) {
                left = 1;
                printf("%c", num[i]);
            }else if(left != 0) {
                printf("%c", num[i]);
            }
            if (i == 0 && left == 0) printf("0");
            
        }
        printf("%c", num[cnt]);
        if(num[cnt] != '%') {
            if(num[cnt] != '/') {

            for(i = len - 1; i > cnt; i--) {
                digit += (long long )(num[i] - '0') * n;
                n *= 10;
            }
            if(digit == 0) printf("0");
            while(digit != 0) {
                printf("%lld", digit%10);
                digit /= 10;
            }
            }else{
                for(i = cnt + 1; i < len - 1; i++) {
                    digit += (long long)(num[i] - '0') * n;
                    n *= 10;
                }
                printf("%lld", digit);
            }
        }
    }
    return 0;
}
