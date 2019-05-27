/*************************************************************************
	> File Name: p1308统计单词数
	> Author: lcnh
	> Mail: 
	> Created Time: 2019年03月16日 星期六 20时45分25秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char word[11];
    char wz[1000001];
    int i = 0, len, len2, s, num, ret;
    int dig = 'a' - 'A';
    gets(word);
    gets(wz);
    len = strlen(wz);
    len2 = strlen(word);
    s = 0;
    num = len;
    for(i = 0; i < len; i++) {
        if(i == 0 || wz[i - 1] == ' ') {
         ret = i;
            for(int j = 0; j < len2; j++) {
                if (wz[i] == word[j] || wz[i] == word[j] + dig || wz[i] == word[j] - dig) {
                    ++i;
                    if((wz[i] == ' ' || wz[i] == '\0') && j == len2 - 1) {
                        s++;
                        if (num > ret) num = ret;
                    }
                } else break;
            }
        }
    }
    if(s) {
        printf("%d ", s);
        printf("%d\n", num);
    }else{
        s--;
        printf("%d\n", s);
    }
}
