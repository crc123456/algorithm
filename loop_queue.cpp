#include <iostream>
#define N 10
using namespace std;

// hh 表示队头，tt表示队尾的后一个位置
int q[N], hh = 0, tt = 0;



int main(){
    // 向队尾插入一个数
    int x = 6;
    q[tt++] = x;
    if(tt == N) tt = 0;

    //从队头弹出一个数
    hh++;
    if(hh == N) hh = 0;

    //队头的值
    cout << q[hh] << endl;

    //判断队列是否为空
    if(hh != tt){
        
    }
    return 0;
}