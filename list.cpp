#include <iostream>
#define N 10
using namespace std;

// head存储链表头，e[]存储节点的值，ne[]存储节点的next指针，idx表示当前用到了哪个节点
int head, e[N], ne[N], idx;

// 初始化
void init(){
    head = -1;
    idx = 0;
}

// 在链表头插入一个数a
void insert(int a){
    e[idx] = a;
    ne[idx] = head;
    head = idx++;
}

// 从链表头开始删除
void remove(){
    head = ne[head];
}

int main(){
    init();
    insert(1);
    insert(2);
    insert(3);
    for (int i = head; ne[i] != -1; i = ne[i]) {
        cout << e[i] << endl;
    }
    return 0;
}