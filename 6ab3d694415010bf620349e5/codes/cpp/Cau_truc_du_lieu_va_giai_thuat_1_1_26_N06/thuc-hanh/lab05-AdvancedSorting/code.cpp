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

    void merge(int l, int m, int r, int &ss){
        int b[100];

        int i = l;
        int j = m + 1;
        int k = l;

        while(i <= m && j <= r){
            ss++;

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

        for(i = l; i <= r; i++){
            a[i] = b[i];
        }
    }

    void mergeSort(int l, int r, int &ss){
        if(l >= r){
            return;
        }

        int m = (l + r) / 2;

        mergeSort(l, m, ss);
        mergeSort(m + 1, r, ss);

        merge(l, m, r, ss);
    }

    void mergeSort(int &ss){
        mergeSort(0, n - 1, ss);
    }

    int partition(int l, int r, int &ss){
        int x = a[r];

        int i = l - 1;

        for(int j = l; j < r; j++){
            ss++;

            if(a[j] < x){
                i++;

                swap(a[i], a[j]);
            }
        }

        swap(a[i + 1], a[r]);

        return i + 1;
    }

    void quickSort(int l, int r, int &ss){
        if(l >= r){
            return;
        }

        int p = partition(l, r, ss);

        quickSort(l, p - 1, ss);
        quickSort(p + 1, r, ss);
    }

    void quickSort(int &ss){
        quickSort(0, n - 1, ss);
    }

    void heap(int n, int i, int &ss){
        int lon = i;

        int trai = 2 * i + 1;
        int phai = 2 * i + 2;

        if(trai < n){
            ss++;

            if(a[trai] > a[lon]){
                lon = trai;
            }
        }

        if(phai < n){
            ss++;

            if(a[phai] > a[lon]){
                lon = phai;
            }
        }

        if(lon != i){
            swap(a[i], a[lon]);

            heap(n, lon, ss);
        }
    }

    void heapSort(int &ss){
        for(int i = n / 2 - 1; i >= 0; i--){
            heap(n, i, ss);
        }

        for(int i = n - 1; i > 0; i--){
            swap(a[0], a[i]);

            heap(i, 0, ss);
        }
    }
};

int main(){
    int x;
    int ss;

    cout << "MERGE SORT\n";

    AdvancedSorting a1;

    a1.nhap();

    cout << "Day ban dau: ";
    a1.xuat();

    ss = 0;

    a1.mergeSort(ss);

    cout << "Day sau khi sap xep: ";
    a1.xuat();

    cout << "So phep so sanh = " << ss << endl;


    cout << "\nQUICK SORT\n";

    AdvancedSorting a2;

    a2.nhap();

    cout << "Day ban dau: ";
    a2.xuat();

    ss = 0;

    a2.quickSort(ss);

    cout << "Day sau khi sap xep: ";
    a2.xuat();

    cout << "So phep so sanh = " << ss << endl;


    cout << "\nHEAP SORT\n";

    AdvancedSorting a3;

    a3.nhap();

    cout << "Day ban dau: ";
    a3.xuat();

    ss = 0;

    a3.heapSort(ss);

    cout << "Day sau khi sap xep: ";
    a3.xuat();

    cout << "So phep so sanh = " << ss << endl;

    return 0;
}