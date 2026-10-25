#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Xe {
    private:
        string bienSoXe;
        double trongLuong;
    public:
        Xe(){
            bienSoXe = "";
            trongLuong = 0.0;
        }
        virtual ~Xe(){}
        void nhap(){
            cout << "Vui long nhap bien so xe: ";
            getline(cin >> ws, bienSoXe);
            cout << "Vui long nhap trong luong: ";
            cin >> trongLuong;
        }
        void xuat() {
            cout << "Bien so: " << bienSoXe << " | Trong luong: " << trongLuong << " tan";
        }
        double getTrongLuong() const{
            return trongLuong;
        }
        virtual int demChoNgoi() = 0;
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
