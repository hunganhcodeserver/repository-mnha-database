#include <bits/stdc++.h>

using namespace std;

class SearchingArray{
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

    int linearSearch(int x, int &ss){
        for(int i = 0; i < n; i++){
            ss++;

            if(a[i] == x){
                return i;
            }
        }

        return -1;
    }

    void sapXep(){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
        }
    }

    int binarySearch(int x, int &ss){
        int l = 0;
        int r = n - 1;

        while(l <= r){
            int m = (l + r) / 2;

            ss++;

            if(a[m] == x){
                return m;
            }

            if(x < a[m]){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return -1;
    }

    int binarySearchDeQuy(int l, int r, int x, int &ss){
        if(l > r){
            return -1;
        }

        int m = (l + r) / 2;

        ss++;

        if(a[m] == x){
            return m;
        }

        if(x < a[m]){
            return binarySearchDeQuy(l, m - 1, x, ss);
        }

        return binarySearchDeQuy(m + 1, r, x, ss);
    }

    int binarySearchDeQuy(int x, int &ss){
        return binarySearchDeQuy(0, n - 1, x, ss);
    }
};

int main(){
    SearchingArray a;

    a.nhap();

    cout << "\nDay ban dau: ";
    a.xuat();

    int x;

    cout << "\nNhap x: ";
    cin >> x;

    int ss = 0;

    int k = a.linearSearch(x, ss);

    cout << "\nLinear Search:" << endl;

    if(k != -1){
        cout << "Vi tri = " << k << endl;
    }
    else{
        cout << "Khong tim thay" << endl;
    }

    cout << "So phep so sanh = " << ss << endl;


    a.sapXep();

    cout << "\nDay sau khi sap xep: ";
    a.xuat();

    ss = 0;

    k = a.binarySearch(x, ss);

    cout << "\nBinary Search vong lap:" << endl;

    if(k != -1){
        cout << "Vi tri = " << k << endl;
    }
    else{
        cout << "Khong tim thay" << endl;
    }

    cout << "So phep so sanh = " << ss << endl;


    ss = 0;

    k = a.binarySearchDeQuy(x, ss);

    cout << "\nBinary Search de quy:" << endl;

    if(k != -1){
        cout << "Vi tri = " << k << endl;
    }
    else{
        cout << "Khong tim thay" << endl;
    }

    cout << "So phep so sanh = " << ss << endl;

    return 0;
}