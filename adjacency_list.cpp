// 邻接表
#include <bits/stdc++.h>
#define N 100
using namespace std;

// 对于每个点k,开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

// 添加一条边a->b, ne[idx] = h[a]即在头结点前插入点
void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int main(){
    // 初始化
    idx = 0;
    memset(h, -1, sizeof h);
    add(1,4);
    add(1,5);
    add(1,6);
    add(2,3);
    add(2,4);
    for(int i = h[1]; i != -1; i = ne[i]){
        int j = e[i];
        cout << j << endl;
    }
    return 0;
}