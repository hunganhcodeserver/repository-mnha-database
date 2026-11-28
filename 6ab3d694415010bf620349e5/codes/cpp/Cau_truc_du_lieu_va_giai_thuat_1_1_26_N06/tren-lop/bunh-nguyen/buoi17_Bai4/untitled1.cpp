#include <bits/stdc++.h>
using namespace std;

// ================= INSERTION SORT =================
void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        // luu phan tu can chen
        int x = a[i];

        // vi tri cuoi cung cua doan da sap xep
        int j = i - 1;

        // dich cac phan tu lon hon x sang ben phai
        while(j >= 0 && a[j] > x){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

// ================= SELECTION SORT =================
void selectionSort(int a[], int n){
    for(int i = 0; i < n; i++){
        // xem a[i] la phan tu nho nhat
        int min = i;

        // tim vi tri phan tu nho nhat trong doan con lai
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

// ================= BUBBLE SORT =================
void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){

            // kiem tra 2 phan tu dung canh nhau
            if(a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// ================= BINARY SEARCH =================
bool binary_search(int *a, int L, int R, int x){
    if(L > R){
        return false;
    }

    int mid = L + (R - L) / 2;

    // tim o giua
    if(a[mid] == x){
        return true;
    }

    // tim nua ben trai
    if(x < a[mid]){
        return binary_search(a, L, mid - 1, x);
    }

    // tim nua ben phai
    if(x > a[mid]){
        return binary_search(a, mid + 1, R, x);
    }

    return false;
}

// ================= QUICK SORT =================
void quickSort(int a[], int L, int R){
    if(L >= R){
        return;
    }

    int i = L;
    int j = R;

    int chot = a[L + (R - L) / 2];

    // tim phan tu ben trai
    while(a[i] < chot){
        i++;
    }

    // tim phan tu ben phai
    while(a[j] > chot){
        j--;
    }

    if(i <= j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;

        i++;
        j--;
    }

    // Sap xep doan con ben trai
    quickSort(a, L, j);

    // Sap xep doan con ben phai
    quickSort(a, i, R);
}

// ================= HEAP SORT =================
void vunDong(int a[], int n, int i){
    int max = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;

    // so sanh voi con trai neu con trai ton tai
    if(trai < n && a[trai] > a[max]){
        max = trai;
    }

    // so sanh voi con phai neu con phai ton tai
    if(phai < n && a[phai] > a[max]){
        max = phai;
    }

    if(max != i){
        int tmp = a[i];

        a[i] = a[max];
        a[max] = tmp;

        vunDong(a, n, max);
    }
}

void heapSort(int a[], int n){
    // tao dong cuc dai
    for(int i = n / 2 - 1; i >= 0; i--){
        vunDong(a, n, i);
    }

    // Dua phan tu lon nhat ve cuoi
    for(int i = n - 1; i > 0; i--){
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        // vun dong i phan tu, chay tu 0 den i - 1
        vunDong(a, i, 0);
    }
}

// ================= MERGE SORT =================

// tron 2 doan [L...mid] va [mid+1...R]
void tron(int a[], int L, int mid, int R){
    int *tmp = new int[R - L + 1];

    int i = L;
    int j = mid + 1;
    int k = 0;

    // chon phan tu nho hon o dau hai doan
    while(i <= mid && j <= R){
        if(a[i] <= a[j]){
            tmp[k++] = a[i++];
        }
        else{
            tmp[k++] = a[j++];
        }
    }

    // lay phan con lai cua doan trai
    while(i <= mid){
        tmp[k++] = a[i++];
    }

    // lay phan con lai cua doan phai
    while(j <= R){
        tmp[k++] = a[j++];
    }

    // copy lai vao mang a
    for(int z = 0; z < k; z++){
        a[L + z] = tmp[z];
    }

    delete[] tmp;
}

void mergeSort(int a[], int L, int R){
    if(L >= R){
        return;
    }

    int mid = L + (R - L) / 2;

    // sap xep nua trai
    mergeSort(a, L, mid);

    // sap xep nua phai
    mergeSort(a, mid + 1, R);

    // tron hai nua lai voi nhau
    tron(a, L, mid, R);
}

// ================= IN MANG =================
void inMang(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// ================= MAIN =================
int main(){
    int n;

    cout << "Nhap so luong phan tu: ";
    cin >> n;

    int a[100];

    cout << "Nhap cac phan tu:" << endl;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << endl;
    cout << "Mang ban dau: ";
    inMang(a, n);

    // Chon 1 thuat toan de sap xep
    insertionSort(a, n);

    cout << "Mang sau khi sap xep: ";
    inMang(a, n);

    // Test binary search
    int x;

    cout << "Nhap x can tim: ";
    cin >> x;

    if(binary_search(a, 0, n - 1, x)){
        cout << "Tim thay " << x << endl;
    }
    else{
        cout << "Khong tim thay " << x << endl;
    }

    return 0;
}