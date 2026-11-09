#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000], isLast = 0; // lỗi sai: biến "final" là từ khóa ngữ cảnh trong C++11, nên đổi tên thành isLast

void ktao(){
    for(int i = 1; i <= n; i++){
        a[i] = i; // lỗi sai: ban đầu viết a[i] = 0, cấu hình đầu tiên phải là 1 2 ... k
    }
}

void sinh(){
    int i = n - 1;
    while(i >= 1 && a[i] > a[i+1]){
    	--i;
	}
	//987654321
	if(i == 0){
		isLast = 1;
	}
	else{
		//tim thang a[j] nho nhat be hon a[i]
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		//Sap xep tang dan [j+1, n]
		reverse(a+i+1, a+n+1); // lỗi sai: ban đầu viết "reversre" (sai chính tả) và a+j+1; đúng phải là reverse(a+i+1, a+n+1), đảo đoạn [i+1, n] chứ không phải [j+1, n]
		
	}
}

int main(){
    freopen("Untitled6.cpp", "r", stdin); 
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]){
	    --i;
	}
	//987654321
	if(i == 0){
	    for(int i = 1; i <= n; i++) cout << i << " ";
	}
	else{
	    //Tim thang a[j] nho nhat > a[i]
	    int j = n;
	    while(a[i] > a[j]) --j;
	    swap(a[i], a[j]);
	    //Sap xep tang dan [i + 1, n]
	    reverse(a + i + 1, a + n + 1);
	    for(int i = 1; i <= n; i++) cout << a[i] << " ";
	}
    return 0;
}