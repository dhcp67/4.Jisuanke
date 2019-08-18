/*************************************************************************
	> File Name: 矩阵螺旋输出.cpp
	> Author: LiChun
	> Mail: 318082789@qq.com
	> Created Time: 2019年08月13日 星期二 15时21分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

enum{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

void print(int arr[][100], int u, int d, int l, int r, int direction) {
    if (u > d || l > r) {
        cout << endl;
        return ;
    } 
    if (direction == RIGHT) {
        for (int i = l; i <= r; i++) {
            cout << arr[u][i];
            if (u == d) {
                if (i != r) cout << " ";
            }
            else cout << " ";
        }
        print(arr, u + 1, d, l, r, DOWN);
    } else if (direction == DOWN) {
        for (int i = u; i <= d; i++) {
            cout << arr[i][r];
            if (l == r) {
                if (i != d) cout << " ";
            }
            else cout << " ";
        }
        print(arr, u, d, l, r - 1, LEFT);
    } else if (direction == LEFT) {
        for (int i = r; i >= l; i--) {
            cout << arr[d][i];
            if (u == d) {
                if (i != l) cout << " ";
            }
            else cout << " ";
        }
        print(arr, u, d - 1, l, r, UP);
    } else {
        for (int i = d; i >= u; i--) {
            cout << arr[i][l];
            if (l == r) {
                if (i != u) cout << " ";
            }
            else cout << " ";
        }
        print(arr, u, d, l + 1, r, RIGHT);
    }
}

int main() {
    int matrix[100][100];
    int m;
    int n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    print(matrix, 0, m - 1, 0, n - 1, RIGHT);
    return 0;
}
