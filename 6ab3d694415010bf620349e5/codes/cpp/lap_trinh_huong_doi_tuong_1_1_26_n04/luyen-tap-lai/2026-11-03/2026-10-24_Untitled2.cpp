//Lop truu tuong, Ham ao thuan tuy (virtual = 0), Ham huy ao, Ke thua (public), 
//Da hinh, Con tro, Cap phat dong (new/delete), vector<XeCon*>, 
//Goi ham lop cha (Xe::nhap, Xe::xuat)

#include<bits/stdc++.h>
using namespace std;

class Xe{
	private:
		string BSX;
		double trongLuong;
	public:
		Xe(){
			BSX = "";
			trongLuong = 0.0;
		}
		virtual ~Xe(){
		}
		void nhap(){
			cout << "===NHAP CAC THONG TIN===\n";
			cout << "Bien so xe: ";
			getline(cin >> ws, BSX);
			cout << "Trong luong (tan): ";
			cin >> trongLuong;
		}
		void xuat(){
			cout << "Bien so xe: " << BSX << " | Trong luong (tan): " << trongLuong;
		}
		double getTrongLuong(){
			return trongLuong;
		}
		virtual int getSoChoNgoi() = 0;
};

class XeCon : public Xe{
	private:
		int soChoNgoi;
	public:
		XeCon(){
			soChoNgoi = 0;
		}
		void nhap(){
			Xe::nhap();
			cout << "So cho ngoi = "; cin >> soChoNgoi;
			cout << endl;
		}
		void xuat(){
			Xe::xuat();
			cout << " | So cho ngoi: " << soChoNgoi;
			cout << endl;
		}
		int getSoChoNgoi(){
			return soChoNgoi;
		}
};

int main(){
	int n;
	cout << "Nhap n = ";
	cin >> n;
	vector<XeCon*> ds(n);
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << "Xe con thu " << i+1 << ":\n";
		cout << endl;
		ds[i] = new XeCon;
		ds[i]->nhap();
	}
	cout << endl;
	
	cout << "== Xe con (< 1 tan, <= 5 cho ngoi) ==" << endl;
	for(int i = 0; i < n; i++){
		if(ds[i]->getTrongLuong() < 1 && ds[i]->getSoChoNgoi() <= 5){
			ds[i]->xuat();
			cout << endl;
		}
	}
	
	double x;
	cout << "\nNhap so thuc x: ";
	cin >> x;
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(ds[i]->getTrongLuong() < x) dem++;
	}
	cout << "=> So xe con (trong luong < x = " << x << "): " << dem << endl;
	
	int maxChoNgoi = 0;
	for(int i = 0; i < n; i++){
		if(ds[i]->getSoChoNgoi() > maxChoNgoi){
			maxChoNgoi = ds[i]->getSoChoNgoi();
		}
	}
	cout << "\n==Xe con co so cho ngoi nhieu nhat==\n";
	for(int i = 0; i < n; i++){
		if(ds[i]->getSoChoNgoi() == maxChoNgoi){
			ds[i]->xuat();
			cout << endl;
		}
	}
	for(int i = 0; i < n; i++){
		delete ds[i];
	}
	return 0;
}