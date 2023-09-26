#include <bits/stdc++.h>
#define N 100
using namespace std;

//对于每个点k,开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
int h[N], e[N], ne[N], idx;

//st[u]表示点u已经被遍历
bool st[N];

//添加一条边a->b
void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//深搜，这是没有环的情况下，就是树的情况，不用取消标记，但是如果是图的情况需要取消标记
// void dfs(int x,int y){
// 	if(vis[x][y])
// 	    return ;
// 	for(int i=0;i<4;i++){//向各个方向 
// 		int fx=x+mov[i][0];
// 		int fy=y+mov[i][1];
// 		if(fx<0||fy<0||fx>=tmp1||fy>=tmp2)//不要越界
// 		    continue;
// 		vis[fx][fy]=1;//标记 
// 		dfs(fx,fy);
// 		vis[fx][fy]=0;//取消标记 
// 	}
// }

void dfs(int u){
    st[u] = true; // st[u]表示点u已经被遍历

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(j == 6) cout << "find" << endl;
        if(!st[j]) dfs(j);
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
    add(5,6);

    //深搜
    dfs(1);
    return 0;
}