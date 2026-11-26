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
        //loi sai: return 0; --> sua thanh: return; 
        //(ham void khong tra ve gia tri)
    }
    dayTang(n-1); //loi goi de quy
    cout << n << " ";
}

int sum(int n){ 
    //loi sai: if sum(int n) --> sua thanh: int sum(int n) (thieu kieu tra ve int)
    if(n == 0){
        return 0; 
        //loi sai: return; --> sua thanh: return 0; 
        //(ham int phai tra ve gia tri, tong khi n = 0 la 0)
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
