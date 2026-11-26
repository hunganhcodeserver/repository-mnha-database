#include <bits/stdc++.h>
using namespace std;

void dayGiam(int n){
    if(n == 0){ //dieu kien dung
        return ;
    }
    cout << n << " ";
    dayGiam(n-1); //loi goi de quy
}

void dayTang(int n){
    if(n == 0){ //dieu kien dung
        return ; //khi ket thuc 
    }
    dayTang(n-1); //loi goi de quy
    cout << n << " ";
}

int sum(int n){ 
    if(n == 0){
        return 0; 
    }
    return n + sum(n-1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    dayGiam(10);
    cout << endl;
    dayTang(10);
    cout << endl;
    cout << sum(5);
    cout << endl;
    
    return 0;
}
