#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000], isLast = 0; // lỗi sai: biến "final" là từ khóa ngữ cảnh trong C++11, nên đổi tên thành isLast

void ktao(){
    for(int i = 1; i <= k; i++){
        a[i] = i; // lỗi sai: ban đầu viết a[i] = 0, cấu hình đầu tiên phải là 1 2 ... k
    }
}

void sinh(){
    // Bat dau tu bit cuoi cung
    int i = k;
    while(i >= 1 && a[i] == n - k + i){ // lỗi sai: ban đầu viết n - k + 1, giá trị lớn nhất của a[i] phải là n - k + i
        --i;
    }
    if(i == 0){
        isLast = 1;
    }
    else{
        a[i]++;
        // i + 1 => k
        for(int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}

int main(){
    freopen("Untitled5.cpp", "r", stdin); 
    cin  >> n >> k;
    int b[1005];
    for(int i = 1; i <= k; i++) cin >> b[i];
    ktao();
    int c = 0, d = 0;
    while(isLast == 0){
    	++c; // tang to hop
    	bool ok = true;
    	for(int j = 1; j <= k; j++){
    		if(a[j] != b[j]){
    			ok = false; break;
			}
		}
		if(ok) d = c;
		sinh();
	}
	cout << c - d + 1 << endl;
    return 0;
}