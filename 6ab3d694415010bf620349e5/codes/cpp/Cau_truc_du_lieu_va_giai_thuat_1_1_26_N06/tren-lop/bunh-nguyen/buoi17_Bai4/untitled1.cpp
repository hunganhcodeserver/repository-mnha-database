#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
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

void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        //xem a[i] la phan tu nho nhat
        int min = i;
        //tim vi tri phan tu nho nhat trong doan con lai
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            //kiem tra 2 phan tu dung canh nhau
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

bool binary_search(int *a, int L, int R, int x){
    if(L > R){
        return false;
    }
    int mid = L(R-L)/2;
    
    //tim o giua
    if(a[mid] == x){
        return true;
    }
    
    //tim nua ben trai
    if(x < a[mid]){
        return binary_search(a, L, mid-1, x);
    }
    
    //tim nua ben phai
    if(x > a[mid]){
        return binary_search(a, mid+1, R, x);
    }
}

void quickSort(int a[], int L, int R){
    if(L >= R){
        return;
    }
    
    int i = L;
    int j = R;
    
    int chot = a[L + (R - L)/2];
    
    //tim phan tu ben trai
    while(a[i] < chot){
        i++;
    }
    
    //tim phan tu ben phai
    while(a[j] > chot){
        j--;
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
