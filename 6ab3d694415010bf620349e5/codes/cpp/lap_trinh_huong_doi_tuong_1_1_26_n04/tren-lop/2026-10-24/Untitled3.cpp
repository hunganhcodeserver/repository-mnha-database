#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Diem {
    private:
        double x;
        double y;
    public:
        Diem(){
            x = 0.0;
            y = 0.0;
        }
        friend istream& operator >>(istream &is, Diem &d){
            cout << "Nhap hoanh do (x): ";
            is >> d.x;
            cout << "Nhap tung do (y): ";
            is >> d.y;
            return is;
        }
        friend ostream& operator <<(ostream &os, Diem d){
            os << "(x, y) = (" << d.x << ", " << d.y << ")";
            return os;
        }
        double khoangCach() const {
            return sqrt(x * x + y * y);
        }
};

void inKhoangCach(vector<Diem> d){
    int n = d.size();
    sort(d.begin(), d.end(), [](const Diem &a, const Diem &b){
        return a.khoangCach() < b.khoangCach();
    });
    cout << "\nCAC DIEM THEO KHOANG CACH DEN GOC TOA DO (TANG DAN):\n";
    double dem = 0;
    for(int i = 0; i < n; i++){
        cout << d[i] << " -> khoang cach = " << d[i].khoangCach() << "\n";
        dem += d[i].khoangCach();
    }
    cout << "\n=> DIEM GAN GOC TOA DO NHAT: " << d[0] << " -> khoang cach = " << d[0].khoangCach() << "\n";
    cout << "\n=> TONG KHOANG CACH CAC DIEM = " << fixed << setprecision(2) << dem;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cout << "Nhap so n_diem = ";
    cin >> n;
    vector <Diem> d(n);
    cout << "\nVUI LONG NHAP TUNG DIEM:\n";
    for(int i = 0; i < n; i++){
        cout << "Diem " << i+1 << ":\n";
        cin >> d[i];
    }
    cout << "\nTUNG DIEM SAU KHI NHAP DU LIEU:\n";
    for(int i = 0; i < n; i++){
        cout << d[i];
    }
    inKhoangCach(d);
    return 0;
}
