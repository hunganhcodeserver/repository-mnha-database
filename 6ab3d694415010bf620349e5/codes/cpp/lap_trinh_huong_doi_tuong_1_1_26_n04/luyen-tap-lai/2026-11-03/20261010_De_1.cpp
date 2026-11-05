//Lop truu tuong, Ham ao thuan tuy (virtual = 0), Ham huy ao, Ke thua (public), 
//Da hinh, Thuoc tinh protected (lop con truy cap truc tiep), 
//Thuoc tinh private (lop con dung getter), Ham tao co doi + goi ham tao lop cha (: 
//ShapePrivate(w, h)), Con tro lop co so, Cap phat dong (new/delete), 
//vector<ShapeProtected*>, vector<ShapePrivate*>, Do-while kiem tra nhap

#include<bits/stdc++.h>

using namespace std;

//===========protected===========
class ShapeProtected{
	protected:
		double width;
		double height;
	public:
		ShapeProtected(){
			width = 0.0;
			height = 0.0;
		}
		virtual ~ShapeProtected(){
		}
		void nhap(){
			cout << "Nhap chieu dai: ";
			cin >> width;
			cout << "Nhap chieu rong: ";
			cin >> height;
		}
		void xuat(){
			cout << "Chieu dai: " << width << ", Chieu rong: " << height;
		}
		double getWidth(){
			return width;
		}
		double getHeight(){
			return height;
		}
		virtual double area() = 0;
};

class TriangleProtected : public ShapeProtected{
	public:
		double area(){
			return (1.0/2) * width * height;
		}
};

class RectangleProtected : public ShapeProtected{
	public:
		double area(){
			return width * height;
		}
};

//===========private===========
class ShapePrivate{
	private:
		double width;
		double height;
	public:
		ShapePrivate(){
			width = 0.0;
			height = 0.0;
		}
		ShapePrivate(double w, double h){
			width = w;
			height = h;
		}
		virtual ~ShapePrivate(){
		}
		void xuat(){
			cout << "Chieu dai: " << width << ", Chieu rong: " << height;
		}
		double getWidth(){
			return width;
		}
		double getHeight(){
			return height;
		}
		virtual double area() = 0;
};

class TrianglePrivate : public ShapePrivate{
	public:
		TrianglePrivate(double w, double h) : ShapePrivate(w, h){
		}
		double area(){
			return (1.0/2) * getWidth() * getHeight();
		}
};

class RectanglePrivate : public ShapePrivate{
	public:
		RectanglePrivate(double w, double h) : ShapePrivate(w, h){
		}
		double area(){
			return getWidth() * getHeight();
		}
};

int main(){
	int n;
	cout << "Nhap n = ";
	cin >> n;
	vector<ShapeProtected*> s1(n);
	vector<ShapePrivate*> s2(n);
	for(int i = 0; i < n; i++){
		int loai;
		do{
			cout << "\nHinh thu " << i + 1 << " (1: Tam giac, 2: Chu nhat): ";
			cin >> loai;
			if(loai != 1 && loai != 2){
				cout << "Chi duoc nhap 1 hoac 2, nhap lai!";
			}
		} while(loai != 1 && loai != 2);
		//phien ban 1: protected, dung ham thanh phan nhap
		if(loai == 1){
			s1[i] = new TriangleProtected();
		}
		else{
			s1[i] = new RectangleProtected();
		}
		s1[i]->nhap();
		//phien ban 2: private, dung ham tao co doi, du lieu lay tu s1
		double w = s1[i]->getWidth();
		double h = s1[i]->getHeight();
		if(loai == 1){
			s2[i] = new TrianglePrivate(w, h);
		}
		else{
			s2[i] = new RectanglePrivate(w, h);
		}
	}
	cout << "\n===== Protected =====\n";
	for(int i = 0; i < n; i++){
		s1[i]->xuat();
		cout << ", Dien tich: " << s1[i]->area() << endl;
	}
	cout << "\n===== Private =====\n";
	for(int i = 0; i < n; i++){
		s2[i]->xuat();
		cout << ", Dien tich: " << s2[i]->area() << endl;
	}
	for(int i = 0; i < n; i++){
		delete s1[i];
		delete s2[i];
	}
	return 0;
}