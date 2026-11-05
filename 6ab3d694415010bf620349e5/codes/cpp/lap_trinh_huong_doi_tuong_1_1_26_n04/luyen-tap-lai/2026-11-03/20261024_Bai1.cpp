//Lop co so, Lop dan xuat, Ke thua (public), Ham ao (virtual), 
//Ham huy ao, Da hinh, Con tro lop co so (Vehicle*), 
//Cap phat dong (new/delete), vector<Vehicle*>, Goi ham lop cha (Vehicle::move), 
//Do-while kiem tra nhap
#include<bits/stdc++.h>

using namespace std;

class Vehicle{
	private:
		string brand;
		double speed;
	public:
		Vehicle(){
			brand = "";
			speed = 0.0;
		}
		virtual ~Vehicle(){
		}
		void nhap(){
			cout << "Hang san xuat: ";
			cin >> brand;
			cout << "Toc do: ";
			cin >> speed;
		}
		virtual void move(){
			cout << "Di chuyen: ";
		}
		void xuat(){
			cout << "Hang san xuat: " << brand << ", Toc do: " << speed << ", ";
			move();
		}
};

class Car : public Vehicle{
	public:
		void move(){
			Vehicle::move();
			cout << "Dong co.\n";
		}
};

class Bicycle : public Vehicle{
	public:
		void move(){
			Vehicle::move();
			cout << "Suc nguoi.\n";
		}
};

class Motorcycle : public Vehicle{
	public:
		void move(){
			Vehicle::move();
			cout << "Dong co.\n";
		}
};

int main(){
	int n;
	cout << "Nhap n = ";
	cin >> n;
	cout << endl;
	vector<Vehicle*> ds(n);
	for(int i = 0; i < n; i++){
		cout << "Xe thu " << i + 1 << ":\n";
		int loai;
		do {
			cout << "Chon loai (1. Car, 2. Bicycle, 3. Motorcycle): ";
			cin >> loai;
			if (loai == 1) ds[i] = new Car;
			else if (loai == 2) ds[i] = new Bicycle;
			else if (loai == 3) ds[i] = new Motorcycle;
		} while(loai < 1 || loai > 3);
		ds[i]->nhap();
		cout << endl;
	}
	cout << "\n===== DANH SACH XE =====\n";
	for(int i = 0; i < n; i++){
		ds[i]->xuat();
	}
	for(int i = 0; i < n; i++){
		delete ds[i];
	}
	return 0;
}