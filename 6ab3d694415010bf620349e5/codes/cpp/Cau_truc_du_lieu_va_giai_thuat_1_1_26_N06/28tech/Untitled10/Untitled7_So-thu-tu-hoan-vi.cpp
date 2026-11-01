#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    freopen("Untitled7.cpp", "r", stdin); 
    int n; cin >> n;
    int a[n + 5], b[n+5];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) a[i] = i;
    int id = 0; // lỗi sai: ban đầu viết id = 1, vì ++id chạy trước khi so sánh nên hoán vị đầu tiên bị tính là 2; phải khởi tạo 0 để hoán vị đầu tiên có thứ tự 1
    do{
    	++id;
    	bool ok = true;
        for(int i = 1; i <= n; i++) ok &= a[i] == b[i];
        if(ok){
        	cout << id << endl; return 0;
		}
    }while(next_permutation(a + 1, a + n + 1));
}