#include <bits/stdc++.h>
using namespace std;

int n, a[1000];
//a[1], a[2], ..., a[n]
bool ok; 


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
        ok = false;      // đã là cấu hình cuối (111...1)
    } else {
        a[i] = 1;
    }
}

int main() {
    freopen("input2.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    ktao();
    while(ok){
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) cout << "B";
            else cout << "A";
        }
        cout << endl;
        sinh();
    }
    return 0;
}
