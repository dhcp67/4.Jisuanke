/*************************************************************************
	> File Name: 更大的行列式.c
	> Author: LiChun
	> Mail: 318082789@qq.com
	> Created Time: 2019年08月07日 星期三 11时33分50秒
 ************************************************************************/


#include <iostream>
using namespace std;

int calc(int arr[][3], int m, int n) {
    int ret = 0;
    if (n != 2) {
        for (int i = 0; i < n; i++) {
            int tmp = 1;
            int ii = i;
            for (int j = 0; j < m; j++, ii++) {
                if (ii >= n) ii = 0;
                tmp *= arr[j][ii];
                //cout << arr[j][ii] << " ";
            }  
            //cout << endl;
            ret += tmp;
        }
            //cout << endl;
        for (int i = 0; i < n; i++) {
            int ii = i;
            int tmp = 1;
            for (int j = m - 1; j >= 0; j--, ii++) {
                if (ii >= n) ii = 0;
                tmp *= arr[j][ii];
                //cout << arr[j][ii] << " ";
            }
            //cout << endl;
            ret -= tmp;
        }
            //cout << endl;
    } else {
        ret = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
    }
    return ret;

}

int main() {
	int arr[3][3];
	int arr2[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)  {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr2[i][j];
        }
    }
    int a = calc(arr, 3, 3);
    int b = calc(arr2, 2, 2);
    int max = (a > b ? a : b);
    cout <<  max << endl;
    return 0;
}
