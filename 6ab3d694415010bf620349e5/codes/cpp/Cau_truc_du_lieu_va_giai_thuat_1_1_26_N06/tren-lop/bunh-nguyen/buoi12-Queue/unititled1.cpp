//=========================================
//=========CAI DAT QUEUE BANG MANG=========
//=========================================

#include <bits/stdc++.h>
using namespace std;

template<class T>

class Queue{
    private:
        T a[100]; //chua cac phan tu - doi tuong
        int F; //chi vi tri cua phan tu dau tien
        int L; //chi o trong tiep theo đe them phan tu
        int num; //so phan tu trong mang
    public:
        Queue(){
            F = L = num = 0;
        }
        
        //size
        int size(){
            return num;
        }
        
        //empty
        bool isEmpty(){
            return num == 0;
        }
        
        //lay ra gia tri dau tien
        T& front(){
            return a[F];
        }
        
        //lay ra gia tri cuoi cung
        T& back(){
            return a[(L-1+100)%100];
            // a[(L-1+N)%N]
        }
        
        void push(T x){
            if(num == 100){
                cout<<"Mang day";
                return;
            }
            a[L] = x;
            L = (L+1)%100; // (L+1)%N
            num++;
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int a, b;
    // cout << "Nhap a, b: ";
    // cin >> a >> b;
    // cout << "Tong = " << a + b << endl;
    
    
    
    
    return 0;
}
