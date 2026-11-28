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
        
        void xoa(SinhVien sv){
            int viTri = timKiemNhiPhan(ma);
            if(viTri == -1){
                cout << "Khong tim thay";
                return;
            }
            ds.erase(ds.begin()+viTri);
        }
        
        void in(){
            for(SinhVien a : ds){
                cout << a << endl;
            }
            
        }
        
        int timKiemNhiPhan(string ma){
            int left = 0;
            int right = (int)ds.size() - 1;
            
            while(left <= right){
                int mid = (left + right)/2;
                
                if(ds[mid].getMa() == ma){
                    return mid;
                }
                
                if(ds[mid].getMa < ma){
                    left = mid + 1;
                }
                
                else{
                    right = mid - 1;
                }
            }
            return -1;
        }
        
        int timKiemTuanTu(string ma){
            // for(int i = 0; i < (int)ds.size(); i++){
            //     if(ds[i].getMa() == ma){
            //         return i;
            //     }
            // }
            
            for(SinhVien a : ds){
                if(ds[i].getMa() == ma){
                    return i;
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
