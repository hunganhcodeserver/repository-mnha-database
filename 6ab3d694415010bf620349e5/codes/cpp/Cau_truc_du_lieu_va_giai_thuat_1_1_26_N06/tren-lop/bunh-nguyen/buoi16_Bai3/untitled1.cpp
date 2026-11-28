#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string ma;
        string ht;
        int nam;
        string gt;
        string lop;
    public:
        SinhVien(){
            ma = ht = gt = lop = "";
            nam = 0;
        }
        string getMa(){
            return ma;
        }
        int getNam(){
            return nam;
        }
        friend istream& operator>>(istream& in, SinhVien& sv){
            cout << "Nhap ma: ";
            getline(in>>ws, sv.ma);
            
            cout << "Nhap ho ten: ";
            getline(in>>ws, sv.ht);
            
            cout << "Nhap nam: ";
            in >> sv.nam;
            
            cout << "Nhap gioi tinh: ";
            getline(in>>ws, sv.gt);
            
            cout << "Nhap lop: ";
            getline(in>>ws, a.lop);
            
            return in;
        }
        friend ostream& operator<<(ostream& out, SinhVien& a){
            out << "MSV: " << a.ma << ", Ho ten: " 
            << a.ht << ", Nam: " << a.nam << 
            ", Gioi tinh: " << a.gt << ", Lop: " << a.lop << endl;
            return out;
        }
};

class QLSV{
    private:
        vector<SinhVien> ds;
    public:
        //Them sinh vien
        void them(SinhVien sv){
            ds.push_back(a);
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
