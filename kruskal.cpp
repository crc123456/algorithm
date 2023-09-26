#include <bits/stdc++.h>
#define N 10
#define M 20
#define INF 0x3f3f3f3f
using namespace std;

int n, m; // n是点数，m是边数
int p[N]; // 并查集的父节点数组

struct Edge{
    int a, b, w;
    bool operator < (const Edge &W) const{
        return w < W.w;
    }
}edges[M];

// 并查集核心操作
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

//复杂度O(mlogm)
// 在图里面贪心找最小边，最终找到最小生成树，判断是否联通用并查集来解决
int kruskal(){
    sort(edges, edges + m);
    for(int i = 1; i <= n; i++){
        p[i] = i; // 初始化并查集
    }
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        // 如果两个连通块不连通，则将这两个连通块合并
        if(a != b){
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if(cnt < n - 1) return INF;
    return res;
}

int main(){
    cin >> n >> m;
    int a, b, w; // a到b，权重为w
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges[i].a = a;
        edges[i].b = b;
        edges[i].w = w;
    }
    cout << kruskal() << endl;
    return 0;
}