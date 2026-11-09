#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, a[10005], isLast = 0;

void ktao(){
    for(int i = 1; i <= k; i++){
        a[i] = 1;
    }
}

void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n){
        --i;
    }
    if(i == 0){
        isLast = 1;
    }
    else{
        ++a[i];
        for(int j = i + 1; j <= k; j++) a[j] = 1; // lỗi sai: ban đầu viết "j <= n" và "a[i] = 1"; vòng lặp phải chạy tới k (độ dài dãy), và phải gán a[j] = 1 (reset các phần tử phía sau i) chứ không phải a[i]
    }
}

int main(){
    freopen("Untitled9.cpp", "r", stdin); 
    cin >> n >> k;
    ktao();
    while(!isLast){
        for(int i = 1; i <= k; i++) cout << a[i];
        cout << endl;
        sinh();
    }
}