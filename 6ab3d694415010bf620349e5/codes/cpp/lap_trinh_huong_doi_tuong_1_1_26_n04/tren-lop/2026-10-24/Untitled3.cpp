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
