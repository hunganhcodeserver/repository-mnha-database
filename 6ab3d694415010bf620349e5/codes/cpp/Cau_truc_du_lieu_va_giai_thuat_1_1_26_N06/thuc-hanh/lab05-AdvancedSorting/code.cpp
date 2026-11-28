#include <bits/stdc++.h>
using namespace std;

class AdvancedSorting{
private:
    int a[100];
    int n;

public:
    void nhap(){
        cout << "Nhap n: ";
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
    }

    void xuat(){
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void merge(int l, int m, int r){
        int b[100];

        int i = l;
        int j = m + 1;
        int k = 0;

        while(i <= m && j <= r){
            if(a[i] < a[j]){
                b[k] = a[i];
                i++;
            }
            else{
                b[k] = a[j];
                j++;
            }
            k++;
        }

        while(i <= m){
            b[k] = a[i];
            i++;
            k++;
        }

        while(j <= r){
            b[k] = a[j];
            j++;
            k++;
        }

        for(int i = 0; i < k; i++){
            a[l + i] = b[i];
        }
    }

    void mergeSort(int l, int r){
        if(l >= r){
            return;
        }

        int m = (l + r) / 2;

        mergeSort(l, m);
        mergeSort(m + 1, r);

        merge(l, m, r);
    }

    int partition(int l, int r){
        int x = a[r];
        int i = l - 1;

        for(int j = l; j < r; j++){
            if(a[j] < x){
                i++;
                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[r]);

        return i + 1;
    }

    void quickSort(int l, int r){
        if(l >= r){
            return;
        }

        int k = partition(l, r);

        quickSort(l, k - 1);
        quickSort(k + 1, r);
    }

    void heap(int n, int i){
        int lon = i;
        int trai = 2 * i + 1;
        int phai = 2 * i + 2;

        if(trai < n && a[trai] > a[lon]){
            lon = trai;
        }

        if(phai < n && a[phai] > a[lon]){
            lon = phai;
        }

        if(lon != i){
            swap(a[i], a[lon]);
            heap(n, lon);
        }
    }

    void heapSort(){
        for(int i = n / 2 - 1; i >= 0; i--){
            heap(n, i);
        }

        for(int i = n - 1; i > 0; i--){
            swap(a[0], a[i]);
            heap(i, 0);
        }
    }

    void mergeSort(){
        mergeSort(0, n - 1);
    }

    void quickSort(){
        quickSort(0, n - 1);
    }
};

int main(){
    AdvancedSorting a;

    a.nhap();

    cout << "\nDay ban dau: ";
    a.xuat();

    // Merge Sort
    clock_t start = clock();

    a.mergeSort();

    clock_t finish = clock();

    cout << "\nMerge Sort: ";
    a.xuat();

    cout << "Thoi gian: "
         << (double)(finish - start) / CLOCKS_PER_SEC
         << " giay" << endl;

    // nhap lai
    cout << "\nNhap lai day cho Quick Sort:\n";
    a.nhap();

    start = clock();

    a.quickSort();

    finish = clock();

    cout << "Quick Sort: ";
    a.xuat();

    cout << "Thoi gian: "
         << (double)(finish - start) / CLOCKS_PER_SEC
         << " giay" << endl;

    // nhap lai
    cout << "\nNhap lai day cho Heap Sort:\n";
    a.nhap();

    start = clock();

    a.heapSort();

    finish = clock();

    cout << "Heap Sort: ";
    a.xuat();

    cout << "Thoi gian: "
         << (double)(finish - start) / CLOCKS_PER_SEC
         << " giay" << endl;

    return 0;
}