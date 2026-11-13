#include<bits/stdc++.h>

using namespace std;

class Diem{
	private:
		double x, y;
	public:
		Diem(){
			x = 0.0;
			y = 0.0;
		}
		friend istream& operator>>(istream &is, Diem &d){
			is >> d.x >> d.y;
			return is;
		}
		friend ostream& operator<<(ostream &os, const Diem &d){
			os << "(x, y) = (" << d.x << ", " << d.y << ")\n";
			return os;
		}
		double khoangCach() const {
			return sqrt(x*x+y*y);
		}
};


int main(){
	int n;
	cout << "Nhap n: ";
	cin >> n;
	if (n <= 0) {
	    cout << "n phai lon hon 0!" << endl;
	    return 1;
	}
	vector<Diem> d(n);
	
	cout << "\n=================NHAP=================\n";
	for(int i = 0; i < n; i++){
		cout << "Nhap hoanh do va tung do diem thu " << i + 1 << ": ";
		cin >> d[i];
	}
	
	cout << "\n=================XUAT=================\n";
	double tongKC = 0;
	for(int i = 0; i < n; i++){
		cout << d[i];
		tongKC += d[i].khoangCach();
	}
	cout << "Tong khoang cach tu cach diem den goc toa do = " << tongKC << endl;
	
	cout << "\n=========DIEM CO KHOANG CACH NHO NHAT=========\n";
	int idxMin = 0;
	for(int i = 1; i < n; i++){
		if(d[idxMin].khoangCach() > d[i].khoangCach()){
			idxMin = i;
		}
	}
	cout << d[idxMin] << ", khoang cach = " << d[idxMin].khoangCach() << endl;
	
	return 0;
}
