#include <bits/stdc++.h>
#define N 100

using namespace std;

typedef pair<int, int> PII;

//using namespace std; //这句话不能放在typedef下面

int n; //点的数量
int h[N], w[N], e[N], ne[N], idx; //邻接表存储所有的边，w[k]代表边的权重
int dist[N]; //存储所有点到1号点的距离
bool st[N]; //存储每个点的最短距离是否已确定

void add(int a, int b, int weight){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = weight;
    h[a] = idx++;
}

struct cmp
{
    bool operator() (const PII p1, const PII p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

priority_queue<PII, vector<PII>, cmp> my_heap;

//求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // priority_queue<PII, vector<PII>, cmp> my_heap; //放在函数里面不知道为什么就会报错
    my_heap.push(make_pair(0,1)); //first存储距离，second存储节点编号

    while(my_heap.size()){
        auto t = my_heap.top();
        my_heap.pop();

        int ver = t.second, distance = t.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){ //i其实就是代表每条边链接ver和j
            int j = e[i];
            // cout << w[i] << endl;
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                my_heap.push(make_pair(dist[j], j));
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[4];
}

int main(){
    //初始化
    idx = 0;
    memset(h, -1, sizeof h);

    //建图
    n = 7;
    add(1, 2, 12);
    add(1, 6, 16);
    add(1, 7, 14);
    add(2, 1, 12);
    add(2, 6, 7);
    add(2, 3, 10);
    add(3, 2, 10);
    add(3, 6, 6);
    add(3, 4, 3);
    add(3, 5, 5);
    add(4, 3, 3);
    add(4, 5, 4);
    add(5, 3, 5);
    add(5, 4, 4);
    add(5, 6, 2);
    add(5, 7, 8);
    add(6, 1, 16);
    add(6, 2, 7);
    add(6, 3, 6);
    add(6, 5, 2);
    add(6, 7, 9);
    add(7, 1, 14);
    add(7, 5, 8);
    add(7, 6, 9);

    cout << dijkstra() << endl;
    return 0;
}