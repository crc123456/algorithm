#include <bits/stdc++.h>
#define N 10
#define M 20
using namespace std;

int n, m; // n表示点数，m表示边数
int dist[N]; // dist[x]存储1到x的最短路距离

// 边，a表示入点，b表示出点，w表示边的权重
struct Edge{
    int a, b, w;
}edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    // 每次迭代的含义就是经过几个点a到达点b的最短路距离
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
            }
        }
    }

    if(dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    cout << bellman_ford() << endl;
    return 0;
}