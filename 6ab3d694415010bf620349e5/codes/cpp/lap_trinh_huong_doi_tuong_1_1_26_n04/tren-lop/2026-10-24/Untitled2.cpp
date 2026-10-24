#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Xe{
    private:
        string bienSoXe;
        double trongLuong;
    public:
        Vehicle(){
            bienSoXe = "";
            trongLuong = 0.0;
        }
        virtual ~Vehicle(){}
        void nhap(){
            cout << "Vui long nhap bien so xe: ";
            getline(cin >> ws, bienSoXe);
            cout << "Vui long nhap trong luong: ";
            cin >> trongLuong;
        }
        virtual void move(){
            cout << "Xe di chuyen bang: ";
        }
        void xuat(){
            cout << "Hang: " << brand << " | Toc do: " << speed << "| ";
            move();
            cout << endl;
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong = " << a + b << endl;
    return 0;
}
