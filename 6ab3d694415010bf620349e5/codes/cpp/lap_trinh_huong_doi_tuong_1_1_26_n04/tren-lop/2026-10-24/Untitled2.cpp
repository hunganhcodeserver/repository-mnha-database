#include <bits/stdc++.h>
using namespace std;

class Xe {
private:
    string bienSoXe;
    double trongLuong;
public:
    Xe() {
        bienSoXe = "";
        trongLuong = 0.0;
    }
    virtual ~Xe() {}
    void nhap() {
        cout << "Vui long nhap bien so xe: ";
        getline(cin >> ws, bienSoXe);
        cout << "Vui long nhap trong luong (tan): ";
        cin >> trongLuong;
    }
    void xuat() {
        cout << "Bien so: " << bienSoXe << " | Trong luong: " << trongLuong << " tan";
    }
    double getTrongLuong() {
        return trongLuong;
    }
    virtual int demChoNgoi() = 0;
};

class XeCon : public Xe {
private:
    int soChoNgoi;
public:
    XeCon() {
        soChoNgoi = 0;
    }
    void nhap() {
        Xe::nhap();
        cout << "Vui long nhap so cho ngoi: ";
        cin >> soChoNgoi;
    }
    void xuat() {
        Xe::xuat();
        cout << " | So cho ngoi: " << soChoNgoi << endl;
    }
    int demChoNgoi() {
        return soChoNgoi;
    }
};

int main() {
    int n;
    cout << "Vui long nhap n: ";
    cin >> n;
    vector<XeCon*> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "\nXe con thu " << i + 1 << ":\n";
        ds[i] = new XeCon;
        ds[i]->nhap();
    }
    cout << "\n== Xe con < 1 tan va <= 5 cho ngoi ==\n";
    for (int i = 0; i < n; i++) {
        if (ds[i]->getTrongLuong() < 1 && ds[i]->demChoNgoi() <= 5) {
            ds[i]->xuat();
        }
    }
    double x;
    cout << "\nNhap so thuc x: ";
    cin >> x;
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i]->getTrongLuong() < x) dem++;
    }
    cout << "So xe con co trong luong nho hon " << x << ": " << dem << endl;
    int maxCho = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i]->demChoNgoi() > maxCho) maxCho = ds[i]->demChoNgoi();
    }
    cout << "\n== Xe con co so cho ngoi nhieu nhat ==\n";
    for (int i = 0; i < n; i++) {
        if (ds[i]->demChoNgoi() == maxCho) ds[i]->xuat();
    }
    for (int i = 0; i < n; i++) delete ds[i];
    return 0;
}