#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Vehicle{
    private:
        string brand;
        double speed;
    public:
        Vehicle(){
            brand = "";
            speed = 0.0;
        }
        void nhap(){
            cout << "Vui long nhap hang: ";
            getline(cin >> ws, brand);
            cout << "Vui long nhap toc do: ";
            cin >> speed;
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    return 0;
}
