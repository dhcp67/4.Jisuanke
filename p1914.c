/*************************************************************************
	> File Name: p1914.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月17日 星期日 22时50分32秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main () {
    char arr[51];
    int n, len;
    scanf("%d", &n);
    int ret = 0;
    scanf("%s^[\n]", &arr);
    len = strlen(arr);
    for (int i = 0; i < len; i++) {
        if(arr[i] + n > 'z') {
            arr[i] == arr[i] + n- 'z' + 'a' -1 ;
        }else {
            arr[i] += n;
        }
    }
    printf("%s", arr);
    return 0;
}
