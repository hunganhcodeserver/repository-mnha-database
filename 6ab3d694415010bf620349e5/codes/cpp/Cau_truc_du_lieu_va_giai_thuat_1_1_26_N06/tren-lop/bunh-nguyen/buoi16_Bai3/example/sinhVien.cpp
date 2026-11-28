#include<iostream>
#include<string>
#include<vector>
using namespace std;

class SinhVien {
	private:
		string ma;
		string hten;
		int nam;
		string gt;
		string lop;
	public:
		SinhVien() {
			ma= hten = gt= lop ="";
			nam = 0;
		}
		string getMa() {
			return ma;
		}
		friend istream& operator>>(istream& in, SinhVien& a) {
			cout<<"Nhap ma:";
			getline(in>>ws,a.ma);

			cout<<"Nhap ho ten:";
			getline(in,a.hten);

			cout<<"Nhap nam:";
			in>>a.nam;

			cout<<"Nhap gtinh:";
			getline(in>>ws,a.gt);

			cout<<"Nhap lop:";
			getline(in, a.lop);

			return in;
		}
		friend ostream& operator<<(ostream& out,SinhVien& a) {
			out<<"Ma sinh vien:"<<a.ma<<"-Ho ten:"<<a.hten
			   <<"-Nam:"<<a.nam<<"-GioiTinh:"<<a.gt<<"-Lop:"<<a.lop<<endl;
			return out;
		}
};

class QLSV {
	private:
		vector<SinhVien> ds;
	public:
		//Them sinh vien
		void them(SinhVien a) {
			ds.push_back(a);
		}

		void xoa(string ma) {
			int viTri = timKiemNhiPhan(ma);
			if(viTri == -1) {
				cout<<"Khong tim thay";
				return;
			}
			ds.erase(ds.begin()+viTri);
		}

		void in() {
			for(SinhVien a : ds) {
				cout<<a<<endl;
			}
		}

		int timKiemNhiPhan(string ma) {
			int left = 0 ;
			int right =(int)ds.size()-1;

			while(left<=right) {
				int mid = (left + right)/2;

				if(ds[mid].getMa() == ma ) {
					return mid;
				}
				if(ds[mid].getMa() < ma) {
					left = mid +1;
				} else {
					right = mid - 1;
				}
			}
			return -1;
		}

		int timKiemTuanTu(string ma) {
			for(int i = 0 ; i < (int)ds.size(); i++) {
				if(ds[i].getMa() == ma) {
					return i;
				}
			}
			
			return -1;
		}

};

int main(){
	QLSV a;
}

