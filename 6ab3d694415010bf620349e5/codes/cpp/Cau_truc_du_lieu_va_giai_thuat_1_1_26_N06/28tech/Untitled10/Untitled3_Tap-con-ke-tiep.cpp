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
    freopen("Untitled3.cpp", "r", stdin); 
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
    	--i;
	}
	if(i == 0){
		for(int j = 1; j <= k; j++) cout << j << " ";
	}
	else{
		a[i]++;
		for(int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
		}
		for(int j = 1; j <= k; j++) cout << a[j] << " ";
	}
	//=============SÂU NHỊ PHÂN===================
//    freopen("Untitled3.cpp", "r", stdin); // lỗi sai: đọc input từ chính file code nên n, k không hợp lệ. Xóa đi, hoặc dùng file input thật như "input.txt"
//    ktao();
//    while(isLast == 0){
//        for(int i = 1; i <= k; i++){
//            cout << a[i] << " ";
//        }
//        cout << endl;
//        sinh();
//    }
    return 0;
}