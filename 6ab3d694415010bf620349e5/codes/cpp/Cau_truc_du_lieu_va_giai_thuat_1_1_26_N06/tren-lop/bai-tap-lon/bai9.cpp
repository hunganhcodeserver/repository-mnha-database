// Bai 9: Quan ly nhan su bang danh sach lien ket don
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

const double LUONG_CO_SO = 1350000;   // Luong = he so luong * 1.350.000
const double NGUONG_HE_SO = 4.4;

struct CanBo {
    int maCB;
    string hoTen;      // ho dem va ten
    string phongBan;
    string chucVu;
    double heSoLuong;
};

struct Node {
    CanBo data;
    Node* next;
    Node(const CanBo& c) : data(c), next(nullptr) {}
};

// ---------- ham ho tro ----------
string chuThuong(string s) {
    for (size_t i = 0; i < s.size(); i++) s[i] = tolower((unsigned char)s[i]);
    return s;
}

// Lay ten (tu cuoi cung) trong ho ten
string layTen(const string& hoTen) {
    size_t cuoi = hoTen.find_last_not_of(' ');
    if (cuoi == string::npos) return "";
    size_t dau = hoTen.find_last_of(' ', cuoi);
    return hoTen.substr(dau == string::npos ? 0 : dau + 1, cuoi - (dau == string::npos ? 0 : dau));
}

// So sanh theo ten, neu trung ten thi so sanh ca ho dem
bool tenNhoHon(const CanBo& a, const CanBo& b) {
    string ta = chuThuong(layTen(a.hoTen)), tb = chuThuong(layTen(b.hoTen));
    if (ta != tb) return ta < tb;
    return chuThuong(a.hoTen) < chuThuong(b.hoTen);
}

string docDong(const string& nhac) {
    string s;
    cout << nhac;
    if (!getline(cin, s)) exit(0);
    return s;
}

int docSoNguyen(const string& nhac) {
    while (true) {
        string s = docDong(nhac);
        try {
            size_t p;
            int v = stoi(s, &p);
            if (p == s.size()) return v;
        } catch (...) {}
        cout << "Gia tri khong hop le, nhap lai.\n";
    }
}

double docSoThuc(const string& nhac) {
    while (true) {
        string s = docDong(nhac);
        try {
            size_t p;
            double v = stod(s, &p);
            if (p == s.size()) return v;
        } catch (...) {}
        cout << "Gia tri khong hop le, nhap lai.\n";
    }
}

// Nhap not cac truong con lai sau khi da co ma can bo
CanBo nhapChiTiet(int ma) {
    CanBo c;
    c.maCB = ma;
    c.hoTen = docDong("  Ho dem, ten : ");
    c.phongBan = docDong("  Phong ban   : ");
    c.chucVu = docDong("  Chuc vu     : ");
    c.heSoLuong = docSoThuc("  He so luong : ");
    return c;
}

double tinhLuong(const CanBo& c) { return c.heSoLuong * LUONG_CO_SO; }

void inTieuDe() {
    cout << left << setw(6) << "Ma" << setw(26) << "Ho ten" << setw(14) << "Phong ban"
         << setw(14) << "Chuc vu" << setw(8) << "He so" << "Luong\n";
    cout << string(80, '-') << "\n";
}

void inCanBo(const CanBo& c) {
    cout << left << setw(6) << c.maCB << setw(26) << c.hoTen << setw(14) << c.phongBan
         << setw(14) << c.chucVu << fixed << setprecision(2) << setw(8) << c.heSoLuong
         << setprecision(0) << tinhLuong(c) << "\n";
}

// ---------- lop danh sach lien ket don ----------
class DanhSachCanBo {
    Node* head;
    Node* tail;
    int n;

public:
    DanhSachCanBo() : head(nullptr), tail(nullptr), n(0) {}
    ~DanhSachCanBo() {
        while (head) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }
    DanhSachCanBo(const DanhSachCanBo&) = delete;
    DanhSachCanBo& operator=(const DanhSachCanBo&) = delete;

    int soLuong() const { return n; }

    void themCuoi(const CanBo& c) {
        Node* p = new Node(c);
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
        n++;
    }

    // Tao danh sach: dung khi nhap ma can bo <= 0
    void taoDanhSach() {
        cout << "Nhap danh sach can bo (ma <= 0 de dung)\n";
        while (true) {
            int ma = docSoNguyen("Ma can bo: ");
            if (ma <= 0) break;
            themCuoi(nhapChiTiet(ma));
        }
    }

    // Them tai vi tri vt (1 <= vt <= n+1); vi tri ngoai doan duoc dua ve hai dau
    void themTaiViTri(const CanBo& c, int vt) {
        if (vt <= 1 || !head) {
            Node* p = new Node(c);
            p->next = head;
            head = p;
            if (!tail) tail = p;
            n++;
        } else if (vt > n) {
            themCuoi(c);
        } else {
            Node* truoc = head;
            for (int i = 1; i < vt - 1; i++) truoc = truoc->next;
            Node* p = new Node(c);
            p->next = truoc->next;
            truoc->next = p;
            n++;
        }
    }

    void inDanhSach() const {
        if (!head) { cout << "Danh sach rong.\n"; return; }
        inTieuDe();
        for (Node* p = head; p; p = p->next) inCanBo(p->data);
    }

    // In can bo co he so luong >= nguong
    void inTheoHeSoLuong(double nguong) const {
        bool coKQ = false;
        for (Node* p = head; p; p = p->next) {
            if (p->data.heSoLuong >= nguong - 1e-9) {
                if (!coKQ) inTieuDe();
                inCanBo(p->data);
                coKQ = true;
            }
        }
        if (!coKQ) cout << "Khong co can bo nao thoa man.\n";
    }

    void timTheoChucVu(const string& chucVu) const {
        string key = chuThuong(chucVu);
        bool coKQ = false;
        for (Node* p = head; p; p = p->next) {
            if (chuThuong(p->data.chucVu) == key) {
                if (!coKQ) inTieuDe();
                inCanBo(p->data);
                coKQ = true;
            }
        }
        if (!coKQ) cout << "Khong tim thay can bo nao.\n";
    }

    void timTheoHeSoVaPhongBan(double heSo, const string& phongBan) const {
        string key = chuThuong(phongBan);
        bool coKQ = false;
        for (Node* p = head; p; p = p->next) {
            if (fabs(p->data.heSoLuong - heSo) < 1e-9 && chuThuong(p->data.phongBan) == key) {
                if (!coKQ) inTieuDe();
                inCanBo(p->data);
                coKQ = true;
            }
        }
        if (!coKQ) cout << "Khong tim thay can bo nao.\n";
    }

    // Sap xep tang dan theo ten (chon truc tiep, doi cho du lieu cac nut)
    void sapXepTheoTen() {
        for (Node* i = head; i && i->next; i = i->next) {
            Node* min = i;
            for (Node* j = i->next; j; j = j->next)
                if (tenNhoHon(j->data, min->data)) min = j;
            if (min != i) swap(i->data, min->data);
        }
    }
};

int main() {
    DanhSachCanBo ds;
    int chon;
    do {
        cout << "\n===== QUAN LY NHAN SU =====\n"
             << "1. Tao danh sach can bo\n"
             << "2. Them can bo tai vi tri\n"
             << "3. Tinh va in luong tat ca can bo\n"
             << "4. In can bo co he so luong >= 4.4\n"
             << "5. Tim can bo theo chuc vu\n"
             << "6. Tim can bo theo he so luong va phong ban\n"
             << "7. Sap xep theo ten\n"
             << "8. In danh sach\n"
             << "0. Thoat\n";
        chon = docSoNguyen("Chon: ");
        switch (chon) {
        case 1: ds.taoDanhSach(); break;
        case 2: {
            int ma = docSoNguyen("Ma can bo: ");
            CanBo c = nhapChiTiet(ma);
            int vt = docSoNguyen("Vi tri them (1.." + to_string(ds.soLuong() + 1) + "): ");
            ds.themTaiViTri(c, vt);
            break;
        }
        case 3: ds.inDanhSach(); break;   // cot Luong = he so * 1.350.000
        case 4: ds.inTheoHeSoLuong(NGUONG_HE_SO); break;
        case 5: ds.timTheoChucVu(docDong("Nhap chuc vu: ")); break;
        case 6: {
            double hs = docSoThuc("Nhap he so luong: ");
            ds.timTheoHeSoVaPhongBan(hs, docDong("Nhap phong ban: "));
            break;
        }
        case 7: ds.sapXepTheoTen(); cout << "Da sap xep.\n"; break;
        case 8: ds.inDanhSach(); break;
        case 0: cout << "Tam biet!\n"; break;
        default: cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);
    return 0;
}
