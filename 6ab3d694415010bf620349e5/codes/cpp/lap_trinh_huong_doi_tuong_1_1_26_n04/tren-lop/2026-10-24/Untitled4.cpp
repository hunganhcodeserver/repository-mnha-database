#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Toado {
    private:
        double x;
        double y;
    public:
        Toado(){
            x = 0.0;
            y = 0.0;
        }
        void nhap(){
            cout << "Nhap hoanh do (x): ";
            cin >> x;
            cout << "Nhap tung do (y): ";
            cin >> y;
        }
        void xuat(){
            cout << "(x, y) = (" << x << ", " << y << ")";
        }
};

class DiemMau : public Toado {
    private:
        int mau;
    public:
        DiemMau() : Toado() {
            mau = 1;
        }
        void nhap(){
            Toado::nhap();                       // nhập x, y bằng hàm của cha
            do {
                cout << "Nhap ma mau (1-Do, 2-Vang, 3-Xanh): ";
                cin >> mau;
            } while(mau < 1 || mau > 3);         // bắt nhập lại nếu sai
        }
        void xuat() const {
            Toado::xuat();                       // in x, y bằng hàm của cha
            cout << ", mau = ";
            if(mau == 1) cout << "Do";
            else if(mau == 2) cout << "Vang";
            else cout << "Xanh";
        }
        int getMau() const {
            return mau;
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cout << "Nhap so n = ";
    cin >> n;

    vector<DiemMau> d(n);
    for(int i = 0; i < n; i++){
        cout << "\nDiem thu " << i + 1 << ":\n";
        d[i].nhap();
    }

    // 1. Thống kê số điểm mỗi màu
    int dem[4] = {0};                            // dùng dem[1], dem[2], dem[3]
    for(int i = 0; i < n; i++){
        dem[d[i].getMau()]++;
    }
    cout << "\nSo diem Do: " << dem[1];
    cout << "\nSo diem Vang: " << dem[2];
    cout << "\nSo diem Xanh: " << dem[3] << "\n";

    // 2. Tìm khoảng cách lớn nhất
    double maxKC = 0;
    for(int i = 0; i < n; i++){
        maxKC = max(maxKC, d[i].khoangCach());
    }

    // 3. In tất cả điểm có khoảng cách = max (có thể có nhiều điểm bằng nhau)
    cout << "\nCac diem xa goc toa do nhat (khoang cach = " << maxKC << "):\n";
    for(int i = 0; i < n; i++){
        if(d[i].khoangCach() == maxKC){
            d[i].xuat();
            cout << "\n";
        }
    }
    return 0;
}
