#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string ma;
        string ht;
        int nam;
        string gt;
        string lop;
    public:
        SinhVien(){
            ma = ht = gt = lop = "";
            nam = 0;
        }
        string getMa(){
            return ma;
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
