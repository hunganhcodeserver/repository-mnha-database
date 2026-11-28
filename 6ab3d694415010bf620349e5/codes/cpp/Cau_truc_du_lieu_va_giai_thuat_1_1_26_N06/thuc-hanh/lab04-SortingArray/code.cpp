#include <bits/stdc++.h>
using namespace std;

class SortingArray{
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

    void bubbleSort(){
        int ss = 0, doi = 0;

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                ss++;

                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                    doi++;
                }
            }
        }

        cout << "Bubble Sort: ";
        xuat();
        cout << "So phep so sanh: " << ss << endl;
        cout << "So lan hoan doi: " << doi << endl;
    }

    void selectionSort(){
        int ss = 0, doi = 0;

        for(int i = 0; i < n - 1; i++){
            int k = i;

            for(int j = i + 1; j < n; j++){
                ss++;

                if(a[j] < a[k]){
                    k = j;
                }
            }

            if(k != i){
                swap(a[i], a[k]);
                doi++;
            }
        }

        cout << "Selection Sort: ";
        xuat();
        cout << "So phep so sanh: " << ss << endl;
        cout << "So lan hoan doi: " << doi << endl;
    }

    void insertionSort(){
        int ss = 0, dich = 0;

        for(int i = 1; i < n; i++){
            int x = a[i];
            int j = i - 1;

            while(j >= 0){
                ss++;

                if(a[j] > x){
                    a[j + 1] = a[j];
                    dich++;
                    j--;
                }
                else{
                    break;
                }
            }

            a[j + 1] = x;
        }

        cout << "Insertion Sort: ";
        xuat();
        cout << "So phep so sanh: " << ss << endl;
        cout << "So lan dich chuyen: " << dich << endl;
    }
};

int main(){
    SortingArray a;

    cout << "Nhap day so: ";
    a.nhap();

    cout << "\nDay ban dau: ";
    a.xuat();

    cout << endl;
    a.bubbleSort();

    a.nhap();

    cout << endl;
    a.selectionSort();

    a.nhap();

    cout << endl;
    a.insertionSort();

    return 0;
}