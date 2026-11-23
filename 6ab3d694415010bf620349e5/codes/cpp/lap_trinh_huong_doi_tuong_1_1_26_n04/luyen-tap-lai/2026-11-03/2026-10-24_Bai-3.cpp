//Ham ban, Nap chong toan tu, Con tro, Cap phat dong (new/delete)
//vector<Diem*>, Ham const, Tham chieu, size_t

#include<bits/stdc++.h>

using namespace std;

class Diem{
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
		friend ostream& operator <<(ostream &os, const Diem &d){
			os << "(x, y) = (" << d.x << ", " << d.y << ")";
			return os;
		}
		double kc() const{
			return sqrt(x*x+y*y);
		}
};

void arrangeMinKC(const vector<Diem*> &d){
	Diem* minKC = d[0];
	for(size_t i = 1; i < d.size(); i++){
		//Ly do int -> size_t
		//int: co dau, so sanh voi d.size() bi canh bao
		//size_t: khong dau, cung kieu voi d.size()
		if(d[i]->kc() < minKC->kc()){
			minKC = d[i];
		}
	}
	cout << "Diem gan toa do nhat: " << *minKC << endl;
}

int main(){
	int n;
	cout << "Nhap n = ";
	cin >> n;
	vector<Diem*> d(n); // Con tro
	for(int i = 0; i < n; i++){
		cout << "Diem " << i + 1 << ":" << endl;
		d[i] = new Diem; // cap phat
		cin >> *d[i];
	}
	cout << "\n==========Data sau khi nhap:==========\n";
	double total = 0.0;
	for(int i = 0; i < n; i++){
		cout << "Diem " << i + 1 << ":" << endl;
		cout << *d[i] << ", khoang cach: " << d[i]->kc() << endl;
		total += d[i]->kc();
	}
	cout << endl;
	cout << "Tong tat ca cac diem den goc toa do = " << total;
	arrangeMinKC(d);
	for(int i = 0; i < n; i++){
		delete d[i];
	}
	return 0;
}