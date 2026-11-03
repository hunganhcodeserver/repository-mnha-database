#include<bits/stdc++.h>

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
		virtual ~Toado(){} // SUA: destructor ao de delete qua con tro co so an toan
		virtual void nhap(){ // SUA: them virtual
			cout << "Nhap x = ";
			cin >> x;
			cout << "Nhap y = ";
			cin >> y;
		}
		virtual void xuat(){ // SUA: them virtual
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
				cout << "Nhap ma mau (1-do, 2-vang, 3-xanh) = ";
				cin >> mau;
			} while(mau < 1 || mau > 3);
			cout << endl;
		}
		void xuat(){
			Toado::xuat();
			cout << ", mau = ";
			if(mau == 1) cout << "Do";
			else if(mau == 2) cout << "Vang";
			else if(mau == 3) cout << "Xanh";
			else cout << "Khong xac dinh";
		}
		int getMau(){
			return mau;
		}
};

int main(){
	int n;
	do{ // SUA: kiem tra n hop le (n > 0)
		cout << "Nhap n = ";
		cin >> n;
	} while(n <= 0); // SUA
	
	vector<DiemMau*> d(n);
	//vector<DiemMau> d(n);
	for(int i = 0; i < n; i++){
		d[i] = new DiemMau(); // SUA: cap phat bang new cho tung phan tu
		cout << "\nDiem thu " << i+1 << "\n";
		d[i]->nhap();
		//d[i].nhap();
	}
	
	int dem[4] = {0}; //0-rong, 1-do, 2-vang, 3-xanh
	for(int i = 0; i < n; i++){
		dem[d[i]->getMau()]++;
		//dem[d[i].getMau()]++;
	}
	cout << "\nSo diem mau do: " << dem[1];
	cout << "\nSo diem mau vang: " << dem[2];
	cout << "\nSo diem mau xanh: " << dem[3];
	cout << endl;
	
	double maxKC = 0;
	for(int i = 0; i < n; i++){
		maxKC = max(maxKC, d[i]->khoangCach());
		//maxKC = max(maxKC, d[i].khoangCach());
	}
	
	cout << "\nCac diem xa goc toa do nhat (khoang cach = " << maxKC << "):\n";
    for(int i = 0; i < n; i++){
        if(fabs(d[i]->khoangCach() - maxKC) < 1e-9){ // SUA: so sanh so thuc bang sai so epsilon thay cho ==
            d[i]->xuat();
            cout << ", khoang cach: " << d[i]->khoangCach();
            cout << endl;
        }
    }
    
    for(int i = 0; i < n; i++){
    	delete d[i];
	}
	return 0;
}