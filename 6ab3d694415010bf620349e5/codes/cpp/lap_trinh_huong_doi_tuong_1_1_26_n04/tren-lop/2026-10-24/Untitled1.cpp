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
        virtual ~Vehicle(){}
        void nhap(){
            cout << "Vui long nhap hang: ";
            getline(cin >> ws, brand);
            cout << "Vui long nhap toc do: ";
            cin >> speed;
        }
        virtual void move(){
            cout << "Xe di chuyen bang: ";
        }
        void xuat(){
            cout << "Hang: " << brand << " | Toc do: " << speed;
        }
};

class Car : public Vehicle{
    public:
        void move(){
            Vehicle::move();
            cout << "Dong co\n";
        }
};

class Bicycle : public Vehicle{
    public:
        void move(){
            Vehicle::move();
            cout << "Suc nguoi\n";
        }
};

class Motorcycle : public Vehicle{
    public:
        void move(){
            Vehicle::move();
            cout << "Dong co\n";
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cout << "Vui long nhap n: ";
    cin >> n;
    vector<Vehicle*> ds(n); // chuan CPP
//    Vehicle* ds[n]; //khong chuan CPP
    for (int i = 0; i < n; i++) {
        cout << "--- Xe " << i + 1 << " ---\n";
        int loai;
		do {
		    cout << "Chon loai (1: Car, 2: Bicycle, 3: Motorcycle): ";
		    cin >> loai;
		    if (loai == 1) ds[i] = new Car;
		    else if (loai == 2) ds[i] = new Bicycle;
		    else if (loai == 3) ds[i] = new Motorcycle;
		    else cout << "Vui long chon lai!\n";
		} while (loai < 1 || loai > 3);   // chon sai thi lap lai
        ds[i]->nhap();
    }
    cout << "\n===== DANH SACH XE =====\n";
    for (int i = 0; i < n; i++) {
        ds[i]->xuat();
    }
    for (int i = 0; i < n; i++) delete ds[i];
    return 0;
}
