#include <bits/stdc++.h>
using namespace std;

class Toado{
	private:
		double x;
		double y;
	public:
		Toado(){
			x = 0.0;
			y = 0.0;
		}
		void nhap(){
			cout << "Nhap x = ";
			cin >> x;
			cout << "Nhap y = ";
			cin >> y;
		}
		void xuat(){
			cout << "(x, y) = (" << x << ", " << y << ")";
		}
		double khoangCach(){
			return sqrt(x * x + y * y);
		}
};

class DiemMau : public Toado{
	private:
		int mau;
	public:
		DiemMau():Toado(){
			mau = 0;
		}
		void nhap(){
			Toado::nhap();
			do{
				cout << "Nhap ma mau (1 Do, 2 Vang, 3 Xanh): ";
				cin >> mau;
			} while(mau < 1 || mau > 3);
		}	
		void xuat(){
			Toado::xuat();
			cout << ", ma mau = ";
			if(mau == 1) cout << "Do\n";
			else if(mau == 2) cout << "Vang\n";
			else if(mau == 3) cout << "Xanh\n";
			else cout << "Khong xac dinh!\n";
		}
		int getMau(){
			return mau;
		}
};

int main(){
	int n;
	cout << "Nhap n: ";
	cin >> n;
	vector<DiemMau*> dm(n);
	for(int i = 0; i < n; i++){
		dm[i] = new DiemMau();
		cout << "Diem mau thu " << i+1 << ":\n";
		dm[i]->nhap();
	}
	cout << "\n=====================XUAT=====================\n";
	for(int i = 0; i < n; i++){
		cout << "Diem mau thu " << i+1 << ":\n";
		dm[i]->xuat();
	}
	
	cout << "\n===========THONG KE SO DIEM MOI MAU===========\n";
	int dem[4] = {0}; //0,1,2,3
	for(int i = 0; i < n; i++){
		dem[dm[i]->getMau()]++;
	}
	cout << "So diem Do: " << dem[1] << endl;
	cout << "So diem Vang: " << dem[2] << endl;
	cout << "So diem Xanh: " << dem[3] << endl;
	
	cout << "\n======KHOANG CACH LON NHAT DEN GOC TOA DO======\n";
	for(int i = 0; i < n; i++){
		cout << "Diem mau thu " << i+1 << " = " << dm[i]->khoangCach();
	}
	
	for(int i = 0; i < n; i++) delete dm[i];
	return 0;
}