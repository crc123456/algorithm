#include <iostream>
#define N 10
using namespace std;

// e[]表示节点的值，l[]表示节点的左指针，r[]表示节点的右指针，idx表示当前用到了哪些节点
int e[N], l[N], r[N], idx;

// 初始化
void init(){
    //0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}

//在节点a的右边插入一个数x
void insert(int a, int x){
    e[idx] = x;
    // 下标为idx的节点x的左指针是a，右指针是a的右指针
    l[idx] = a, r[idx] = r[a];
    // 下标为r[a]的左指针是下标为idx， a的右指针是下标为idx的节点x，然后idx++
    l[r[a]] = idx, r[a] = idx++;
}

//删除节点a
void remove(int a){
    // a的右指针的左指针是a的左指针
    l[r[a]] = l[a];
    // a的左指针的右指针是a的右指针
    r[l[a]] = r[a];
}

int main(){
    init();
    e[0] = 1;
    e[1] = 4;
    insert(0, 2);
    insert(2, 3);
    for (int i = 0; i != 1; i = r[i]){
        cout << e[i] << endl;
    }
    return 0;
}