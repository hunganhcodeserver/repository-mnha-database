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
            cout << "Nhap ma: " << endl;
            getline(in >> ws, sv.ma);

            cout << "Nhap ho ten: " << endl;
            getline(in >> ws, sv.ht);

            cout << "Nhap nam: " << endl;
            in >> sv.nam;

            cout << "Nhap gioi tinh: " << endl;
            getline(in >> ws, sv.gt);

            cout << "Nhap lop: " << endl;
            getline(in >> ws, sv.lop);

            return in;
        }

        friend ostream& operator<<(ostream& out, SinhVien& a){
            out << "MSV: " << a.ma
                << ", Ho ten: " << a.ht
                << ", Nam: " << a.nam
                << ", Gioi tinh: " << a.gt
                << ", Lop: " << a.lop
                << endl;

            return out;
        }
};

class QLSV{
    private:
        vector<SinhVien> ds;

    public:
        // Them sinh vien
        void them(SinhVien sv){
            ds.push_back(sv);
        }

        void xoa(SinhVien sv){
            int viTri = timKiemNhiPhan(sv.getMa());

            if(viTri == -1){
                cout << "Khong tim thay" << endl;
                return;
            }

            ds.erase(ds.begin() + viTri);
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

        int timKiemTuanTu(string ma){
            int i = 0;

            for(SinhVien a : ds){
                if(a.getMa() == ma){
                    return i;
                }

                i++;
            }

            return -1;
        }
};

int main(){
    freopen("input.txt", "r", stdin);

    QLSV ql;

    SinhVien sv1, sv2;

    cout << "Nhap sinh vien 1:" << endl;
    cin >> sv1;

    cout << endl;

    cout << "Nhap sinh vien 2:" << endl;
    cin >> sv2;

    ql.them(sv1);
    ql.them(sv2);

    cout << endl;
    cout << "Danh sach sinh vien:" << endl;
    ql.in();

    string ma;

    cout << endl;
    cout << "Nhap ma sinh vien can tim: " << endl;
    cin >> ma;

    int viTri = ql.timKiemTuanTu(ma);

    if(viTri == -1){
        cout << "Khong tim thay" << endl;
    }
    else{
        cout << "Tim thay sinh vien o vi tri: "
             << viTri << endl;
    }

    viTri = ql.timKiemNhiPhan(ma);

    if(viTri == -1){
        cout << "Khong tim thay bang tim kiem nhi phan" << endl;
    }
    else{
        cout << "Tim thay bang tim kiem nhi phan o vi tri: "
             << viTri << endl;
    }

    return 0;
}