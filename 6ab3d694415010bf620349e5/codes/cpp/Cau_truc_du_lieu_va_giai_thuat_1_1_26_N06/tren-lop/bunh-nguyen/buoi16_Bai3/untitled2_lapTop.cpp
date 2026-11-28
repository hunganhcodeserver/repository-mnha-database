#include <bits/stdc++.h>
using namespace std;

class lapTop{
    private:
        string ma;
        string hang;
        string ten;
        string cauHinh;
        double gia;
        int sl;

    public:
        string getMa(){
            return ma;
        }

        string getHang(){
            return hang;
        }

        double tien(){
            return gia * sl;
        }

        friend istream& operator>>(istream& is, lapTop& a){
            cout << "Nhap ma: ";
            getline(is >> ws, a.ma);

            cout << "Nhap hang: ";
            getline(is >> ws, a.hang);

            cout << "Nhap ten may: ";
            getline(is >> ws, a.ten);

            cout << "Nhap cau hinh: ";
            getline(is >> ws, a.cauHinh);

            cout << "Nhap gia: ";
            is >> a.gia;

            cout << "Nhap so luong: ";
            is >> a.sl;

            return is;
        }

        friend ostream& operator<<(ostream& os, const lapTop& a){
            os << "Ma may: " << a.ma
               << ", Hang: " << a.hang
               << ", Ten may: " << a.ten
               << ", Cau hinh: " << a.cauHinh
               << ", Gia: " << a.gia
               << ", So luong: " << a.sl
               << endl;

            return os;
        }
};

class QLLT{
    private:
        vector<lapTop> ds;

    public:

        void them(lapTop a){
            for(int i = 0; i < ds.size(); i++){
                if(ds[i].getMa() == a.getMa()){
                    cout << "Ma may da ton tai" << endl;
                    return;
                }
            }

            ds.push_back(a);
        }

        double tinhTong(string hang){
            double tong = 0;

            for(int i = 0; i < ds.size(); i++){
                if(ds[i].getHang() == hang){
                    tong = tong + ds[i].tien();
                }
            }

            return tong;
        }

        void in(){
            for(lapTop a : ds){
                cout << a << endl;
            }
        }

        int timKiemNhiPhan(string ma){
            int left = 0;
            int right = (int)ds.size() - 1;

            while(left <= right){
                int mid = (left + right) / 2;

                if(ds[mid].getMa() == ma){
                    return mid;
                }

                if(ds[mid].getMa() < ma){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            return -1;
        }
};

int main(){
    // Doc input tu file
    freopen("input1.txt", "r", stdin);
    // Khong freopen output
    // => cout van in ra man hinh
    QLLT ql;
    int n;
    cout << "Nhap so luong laptop: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        lapTop a;
        cout << "\n===== Nhap laptop thu " << i + 1 << " =====" << endl;
        cin >> a;
        ql.them(a);
    }
    cout << "\n===== DANH SACH LAPTOP =====" << endl;
    ql.in();
    string hang;
    cout << "\nNhap hang can tinh tong tien: ";
    getline(cin >> ws, hang);
    cout << "Tong tien cua hang " << hang << " = "
         << ql.tinhTong(hang) << endl;
    string ma;
    cout << "\nNhap ma laptop can tim: ";
    getline(cin >> ws, ma);
    int vt = ql.timKiemNhiPhan(ma);
    if(vt != -1){
        cout << "Tim thay laptop tai vi tri: " << vt << endl;
    }
    else{
        cout << "Khong tim thay laptop!" << endl;
    }
    return 0;
}