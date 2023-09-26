#include <bits/stdc++.h>

using namespace std;

void quick_sort(int q[], int l, int r){
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j+1, r);
}

int main(){
    int q[6] = {2,5,4,3,1,6};
    quick_sort(q, 0, 5);
    for(int i = 0; i < 6; i++){
        cout << q[i] << " ";
    }
    return 0;
}