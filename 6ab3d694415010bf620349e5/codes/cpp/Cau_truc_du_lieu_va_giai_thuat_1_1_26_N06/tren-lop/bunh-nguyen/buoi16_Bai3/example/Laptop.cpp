
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Laptop {
	private:
		string ma;
		string hang;
		string ten;
		string cauHinh;
		double gia;
		int sl;

	public:
		string getMa() {
			return ma;
		}

		string getHang() {
			return hang;
		}

		double tien() {
			return gia * sl;
		}

		friend istream& operator>>(istream& in, Laptop& a) {
			cout << "Nhap ma: ";
			getline(in >> ws, a.ma);

			cout << "Nhap hang: ";
			getline(in, a.hang);

			cout << "Nhap ten may: ";
			getline(in, a.ten);

			cout << "Nhap cau hinh: ";
			getline(in, a.cauHinh);

			cout << "Nhap gia: ";
			in >> a.gia;

			cout << "Nhap sl: ";
			in >> a.sl;

			return in;
		}

		friend ostream& operator<<(ostream& out, Laptop& a) {
			out << "Ma may: " << a.ma
			    << " - Hang: " << a.hang
			    << " - Ten may: " << a.ten
			    << " - Cau hinh: " << a.cauHinh
			    << " - Gia: " << a.gia
			    << " - So luong: " << a.sl << endl;
			return out;
		}
};

class QLLT {
	private:
		list<Laptop> ds;

	public:
		void them(Laptop a) {
			for (Laptop x : ds) {
				if (x.getMa() == a.getMa()) {
					cout << "Ma da ton tai!\n";
					return;
				}
			}
			ds.push_back(a);
		}

		void xoa(string ma) {
			for (auto it = ds.begin(); it != ds.end(); ++it) {
				if (it->getMa() == ma) {
					ds.erase(it);
					return;
				}
			}
		}

		double tinhTong(string hang) {
			double tong = 0;

			for (Laptop a : ds) {
				if (a.getHang() == hang) {
					tong = tong + a.tien();
				}
			}

			return tong;
		}

		void in() {
			for (Laptop a : ds) {
				cout << a << endl;
			}
		}

		int timKiemTuanTu(string ma) {
			int i = 0;

			for (Laptop a : ds) {
				if (a.getMa() == ma) {
					return i;
				}
				i++;
			}

			return -1;
		}
};
