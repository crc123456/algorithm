#include <bits/stdc++.h>
#define N 100
using namespace std;

//n是点数，m是边数
int n, m;
//d[i]存储i的入度，q[i]用数组来模拟队列
int d[N], q[N];

// 对于每个点k,开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b
void add(int a, int b){
	e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
    d[b] += 1;
}

bool topsort(){
    int hh = 0, tt = -1;

    //d[i]存储i的入度
    for(int i = 1; i <= n; i++){
        if(!d[i]){
            q[++tt] = i; //入度为0的话就加入队列
        }
    }
    while(hh <= tt){
        int t = q[hh++]; //每次取队头

        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0){ //d[j]入度-1，代表去掉i这个点，如果入度也变为0的话就加入队列
                q[++tt] = j;
            }
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列
    return tt == n - 1;
}

int main(){
    // 初始化
    idx = 0;
    memset(h, -1, sizeof h);

    //建图
    n = 4;
    m = 4;
    add(1,2);
    add(1,3);
    add(2,4);
    // add(4,1);

    cout << topsort() << endl;
    return 0;
}