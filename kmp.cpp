#include <bits/stdc++.h>

using namespace std;

// next数组
int ne[10];

int kmp(string s, string p, int n, int m){
    // s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
    //求模式串的Next数组
    for(int i = 2, j = 0; i < m; i++){
        while(j && p[i-1] != p[j]) j = ne[j];
        if(p[i-1] == p[j]) j++;
        ne[i] = j;
    }

    cout << "next: ";
    for(int i = 0; i < m; i++){
        cout << ne[i] << " ";
    }
    cout << endl << endl;

    //匹配
    for(int i = 0, j = 0; i < n; i++){
        while(j && s[i] != p[j]) j = ne[j];
        if(s[i] == p[j]) j++;
        if(j == m){
            j = ne[j];
            //匹配成功后的逻辑
            return i - m + 1;
        }
    }
    return 0;
}

int main(){
    string s = "ababaabaabaca";
    string p = "abaabaca";
    ne[0] = -1;
    ne[1] = 0;
    cout << kmp(s, p, s.size(), p.size()) << endl;
    return 0;
}