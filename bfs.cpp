#include <bits/stdc++.h>
#define N 100
using namespace std;

//对于每个点k,开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

//st[u]表示点u已经被遍历
bool st[N];

// 添加一条边a->b
void add(int a, int b){
    // 下标为idx的点为b
    e[idx] = b;
    // 下标为idx的点的下一个点为点a的头节点，相当于前插
    ne[idx] = h[a];
    // 点a的头节点变为下标为idx的点b，然后idx++，为下一个做准备
    h[a] = idx++;
}

void bfs(int a){
    queue<int> q;
    st[a] = true; // 表示a号点已经被遍历过
    q.push(a);

    while(q.size()){
        int t = q.front();
        q.pop();

        // 遍历t所有可以走到的点，h[t]存储这个单链表的头节点
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(j == 8) cout << "find" << endl;
            if(!st[j]){
                st[j] = true; // 表示点j已经被遍历过了
                q.push(j);
            }
        }
    }
}

int main(){
    //初始化
    idx = 0;
    memset(h, -1, sizeof h);

    //建树
    add(1,2);
    add(1,3);
    add(2,4);
    add(2,5);
    add(3,6);
    add(3,7);
    add(7,8);

    //广搜
    bfs(1);
    return 0;
}