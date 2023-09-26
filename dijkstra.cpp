#include <bits/stdc++.h>
#define N 10
using namespace std;

int g[N][N]; // 存储每条边
int dist[N]; // 存储1号点到每个点的最短距离
bool st[N]; // 存储每个点的最短路是否已经确定

int n, m;

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for(int i = 2; i <= n; i++){
        // 在还未确定最短路的点中，寻找距离最小的点
        int t = -1; // 首先，将变量 t 初始化为 -1，表示当前还未找到符合条件的点
        // 然后，通过一个循环遍历所有点 j，判断以下两个条件：
        // 1、如果点 j 的最短路径未确定（即 !st[j]）。
        // 2、如果当前找到的点 t 还未确定，或者点 j 的最短路径距离更小（即 dist[t] > dist[j]）。
        // 如果上述两个条件都满足，将 t 更新为 j。
        // 循环结束后，t 就是距离最小且最短路径未确定的点。
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        // 用t更新其他点的距离
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }

        st[t] = true;
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    int a, b, w;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        g[a][b] = w;
    }
    cout << dijkstra() << endl;
    return 0;
}