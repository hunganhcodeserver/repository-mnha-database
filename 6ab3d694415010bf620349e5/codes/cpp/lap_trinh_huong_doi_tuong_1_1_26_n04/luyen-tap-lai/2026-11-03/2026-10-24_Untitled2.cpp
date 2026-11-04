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
		void xuat(){ // lỗi sai: ban đầu viết "void nhap()" lần thứ hai (trùng tên, không biên dịch được); hàm này in thông tin nên phải đặt tên xuat
			Xe::xuat(); // lỗi sai: ban đầu gọi Xe::nhap(); hàm xuất phải gọi Xe::xuat() để in biển số và trọng lượng
			cout << " | So cho ngoi: " << soChoNgoi;
			cout << endl;
		}
		int getSoChoNgoi(){ // lỗi sai: ban đầu thiếu override hàm thuần ảo getSoChoNgoi() của Xe; XeCon phải định nghĩa hàm này, nếu không XeCon là lớp trừu tượng và "new XeCon" báo lỗi
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
			ds[i]->xuat(); // lỗi sai: ban đầu viết "xuat" thiếu cặp ngoặc (), đó chỉ là tên hàm chứ chưa gọi hàm
			cout << endl; // lỗi sai: ban đầu thiếu xuống dòng, các xe sẽ bị in dính vào nhau trên một dòng
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
		if(ds[i]->getSoChoNgoi() == maxChoNgoi){ // lỗi sai: ban đầu viết "getSoChoNgoi == maxCho", thiếu () khi gọi hàm và sai tên biến (maxCho chưa khai báo, phải là maxChoNgoi)
			ds[i]->xuat(); // lỗi sai: ban đầu viết "xuat" thiếu cặp ngoặc ()
			cout << endl; // lỗi sai: ban đầu thiếu xuống dòng giữa các xe
		}
	}
	for(int i = 0; i < n; i++){
		delete ds[i];
	}
	return 0;
}