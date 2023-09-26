#include <bits/stdc++.h>
#define N 10
#define INF 0x3f3f3f3f
using namespace std;

int n = 6;
int d[N][N];

//复杂度O(n^3)，找任意两个点的最短距离
void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
    //初始化
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    d[1][6] = 4;
    d[1][2] = 1;
    d[2][6] = 2;
    floyd();
    cout << d[1][6] << endl;
    return 0;
}