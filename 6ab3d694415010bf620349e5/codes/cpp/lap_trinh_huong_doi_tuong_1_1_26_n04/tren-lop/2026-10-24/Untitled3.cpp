#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Diem {
    private:
        double x;
        double y;
    public:
        friend istream& operator >>(istream &is, Diem &d){
            cout << "Nhap tung do (y): ";
            is >> d.y;
            cout << "Nhap hoanh do (x): ";
            is >> d.x;
            return is;
        }
        friend ostream& operator <<(ostream &os, Diem d){
            os << "(x, y) = (" << d.x << ", " << d.y << ")";
            return os;
        }
        double getX() const {
            return d.x;
        }
        double getY() const {
            return d.y;
        }
};

void khoangCach(Diem d[], int n){
    
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cout << "Nhap so n_diem = ";
    cin >> n;
    vector <Diem*> d(n);
    cout << "\nVUI LONG NHAP TUNG DIEM:\n";
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    cout << "\nTUNG DIEM SAU KHI NHAP DU LIEU:\n";
    for(int i = 0; i < n; i++){
        cout << d[i];
    }
    
    for(int i = 0; i < n; i ++)    delete d[n];
    return 0;
}
