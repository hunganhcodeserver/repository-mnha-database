#include <bits/stdc++.h>
using namespace std;

void insertSort(int a[], int n){
    for(int i = 1; i < n; i++){
        //luu phan tu can chen
        int x = a[i];
        
        //vi tri cuoi cung cua doan da sap xep
        int j = i - 1;
        
        //dich cac phan tu lon hon x sang ben phai
        while(j >= 0 && a[j] > x){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = x;
        
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong = " << a + b << endl;
    return 0;
}
