#include <iostream>
#define N 10
using namespace std;

// hh表示队头，tt表示队尾
int q[N], hh = 0, tt = -1;

int main(){
    //向队尾插入一个数
    int x = 6;
    q[++tt] = x;

    // 从队头弹出一个数
    hh++;

    // 队头的值
    cout << q[hh];

    // 判断队列是否为空
    if (hh <= tt)
    {

    }
    return 0;
}