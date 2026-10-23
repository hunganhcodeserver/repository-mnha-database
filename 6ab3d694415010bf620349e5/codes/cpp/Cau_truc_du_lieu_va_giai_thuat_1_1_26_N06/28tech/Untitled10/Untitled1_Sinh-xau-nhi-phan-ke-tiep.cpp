#include <bits/stdc++.h>
using namespace std;

int n, a[1000];
//a[1], a[2], ..., a[n]

void ktao(){
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    //Bat dau tu bit cuoi cung
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if(i == 0){
        final = 1;
    } else {
        a[1] = 1;
    }
}

int main() {
    freopen("input1.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    ktao();
    while(final == 0){
        for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}
