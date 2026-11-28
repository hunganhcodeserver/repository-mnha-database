#include <bits/stdc++.h>
using namespace std;

class lapTop(){
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
            getline(is>>ws, a.ma);
            
            cout << "Nhap hang: ";
            getline(is>>ws, a.hang);
            
            cout << "Nhap ten may: ";
            getline(is>>ws, a.ten);
            
            cout << "Nhap cau hinh: ";
            getline(is>>ws, a.cauHinh);
            
            cout << "Nhap gia: ";
            in >> a.gia;
            
            cout << "Nhap so luong: ";
            in >> a.sl;
            
            return is;
        }
        
        friend ostream& operator<<(ostream& os, lapTop& a){
            out << "Ma may: " << a.ma
            << ", Hang: " << a.hang
            << ", Ten may: " << a.ten
            << ", Cau hinh: " << a.cauHinh
            << ", Gia: " << a.gia
            << ", So luong: " << a.sl << endl;
            return os;
        }
};

class QLLT{
    private:
        list<Laptop>ds;
    public:
        void them(lapTop a){
            for(int i = 0; i < ds.size(); i++){
                if(ds[i].getMa() == a.getMa()){
                    cout << "Ma may da ton tai";
                    return;
                }
            }
            ds.push_back(a);
        }
        
        double tinhTong(string hang){
            double tong = 0;
            
            for(int = 0; i < ds.size(); i++){
                if(ds[i].getHang == hang){
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
            int right = (int)ds.size()-1;
            
            while(left <= right){
                int mid = (left + right)/2;
                
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

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong = " << a + b << endl;
    return 0;
}
