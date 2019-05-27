/*************************************************************************
	> File Name: juzhenchengfa.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月19日 星期二 19时14分54秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int matrix_a[10][10];
    int matrix_b[10][10];
	int matrix[10][10];
    int m, ret, cnt, n, te;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
	    for(int j = 0; j < n; j++) {
	        scanf("%d", &matrix_a[i][j]);
	    }
	}
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < m; j++) {
	        scanf("%d", &matrix_b[i][j]);
	    }
	}  
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            te = 0;
            for(int l = 0; l < n; l++) {
                te += matrix_a[i][l] * matrix_b[l][j];
            }
            matrix[i][j] = te;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0;j < m; j++) {
            printf("%d", matrix[i][j]);
            if(j != m - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
