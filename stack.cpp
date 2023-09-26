#include <iostream>
#define N 10
using namespace std;

// tt表示栈顶
int stk[N], tt = 0;



int main(){
    // 向栈顶插入一个数
    int x = 6;
    stk[++tt] = x;

    // 从栈顶弹出一个数
    tt -- ;

    // 栈顶的值
    stk[tt];

    // 判断栈是否为空
    if (tt > 0)
    {

    }
    return 0;
}