#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k, a[10005], isLast = 0;

void ktao(){
    for(int i = 1; i <= n; i++){
        a[i] = 0;
    }
}

void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        --i; // lỗi sai: ban đầu thiếu --i, nên khi a[i] == 1 vòng lặp chạy vô hạn vì i không giảm; phải lùi i về trái sau khi đặt a[i] = 0 (phép cộng 1 trong hệ nhị phân có nhớ)
    }
    if(i == 0){
        isLast = 1;
    }
    else{
        a[i] = 1;
    }
}

int main(){
    freopen("Untitled10.cpp", "r", stdin); 
    cin >> n;
    ktao();
	int b[1005];
	for(int i = 1; i <= n; i++) cin >> b[i];
	ll ans = LLONG_MAX;
	while(!isLast){
	    ll s1 = 0, s2 = 0;
	    for(int i = 1; i <= n; i++){
	        if(a[i] == 1) s1 += b[i];
	        else s2 += b[i];
	    }
	    ans = min(ans, abs(s1 - s2));
	    sinh();
	}
	cout << ans << endl;
}