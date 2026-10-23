#include <bits/stdc++.h>
using namespace std;

int n, a[1000];
bool ok;

void ktao(){
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i;
    }
    if(i == 0){
        ok = false;      // đã là cấu hình cuối
    } else {
        a[i] = 1;        // sửa a[1] -> a[i]
    }
}

int main() {
    freopen("input2.txt", "r", stdin);
    cin >> n;
    ktao();
    ok = true;           // thêm dòng này
    while(ok){
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) cout << "B";
            else cout << "A";
        }
        cout << endl;    // xuống dòng
        sinh();          // đưa ra ngoài vòng for
    }
    return 0;
}