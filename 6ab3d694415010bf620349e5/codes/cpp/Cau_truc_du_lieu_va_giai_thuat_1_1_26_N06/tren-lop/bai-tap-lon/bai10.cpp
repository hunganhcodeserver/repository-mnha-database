// Bai 10: Kiem tra loi chinh ta van ban tieng Anh bang bang bam
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

string chuanHoa(const string& s) {
    size_t d = s.find_first_not_of(" \t\r\n");
    if (d == string::npos) return "";
    size_t c = s.find_last_not_of(" \t\r\n");
    string r = s.substr(d, c - d + 1);
    for (size_t i = 0; i < r.size(); i++) r[i] = tolower((unsigned char)r[i]);
    return r;
}

// ---------- bang bam (xu ly dung do bang danh sach lien ket) ----------
class BangBam {
    struct Nut {
        string khoa;
        Nut* tiep;
        Nut(const string& k, Nut* t) : khoa(k), tiep(t) {}
    };
    Nut** bang;
    size_t soNgan;
    size_t soPhanTu;

    static size_t bam(const string& s, size_t m) {
        unsigned long long h = 5381;                 // ham bam djb2
        for (size_t i = 0; i < s.size(); i++) h = h * 33 + (unsigned char)s[i];
        return h % m;
    }

    void bamLai() {                                  // tang gap doi so ngan
        size_t moi = soNgan * 2 + 1;
        Nut** bangMoi = new Nut*[moi]();
        for (size_t i = 0; i < soNgan; i++) {
            Nut* p = bang[i];
            while (p) {
                Nut* ke = p->tiep;
                size_t v = bam(p->khoa, moi);
                p->tiep = bangMoi[v];
                bangMoi[v] = p;
                p = ke;
            }
        }
        delete[] bang;
        bang = bangMoi;
        soNgan = moi;
    }

public:
    BangBam(size_t m = 1009) : bang(new Nut*[m]()), soNgan(m), soPhanTu(0) {}
    ~BangBam() {
        for (size_t i = 0; i < soNgan; i++) {
            Nut* p = bang[i];
            while (p) { Nut* ke = p->tiep; delete p; p = ke; }
        }
        delete[] bang;
    }
    BangBam(const BangBam&) = delete;
    BangBam& operator=(const BangBam&) = delete;

    size_t kichThuoc() const { return soPhanTu; }

    bool co(const string& khoa) const {
        for (Nut* p = bang[bam(khoa, soNgan)]; p; p = p->tiep)
            if (p->khoa == khoa) return true;
        return false;
    }

    // Tra ve true neu them moi, false neu da ton tai
    bool them(const string& khoa) {
        if (co(khoa)) return false;
        if (soPhanTu + 1 > soNgan * 3 / 4) bamLai();
        size_t v = bam(khoa, soNgan);
        bang[v] = new Nut(khoa, bang[v]);
        soPhanTu++;
        return true;
    }

    void layTatCa(vector<string>& kq) const {
        for (size_t i = 0; i < soNgan; i++)
            for (Nut* p = bang[i]; p; p = p->tiep) kq.push_back(p->khoa);
    }
};

// ---------- tu dien ----------
class TuDien {
    BangBam bang;
    bool daThayDoi;

public:
    TuDien() : daThayDoi(false) {}

    // Nap tu file (moi dong mot tu). Tra ve so tu da nap, -1 neu khong mo duoc file
    int napTuFile(const string& duongDan) {
        ifstream f(duongDan.c_str());
        if (!f) return -1;
        string dong;
        int dem = 0;
        while (getline(f, dong)) {
            string w = chuanHoa(dong);
            if (!w.empty() && bang.them(w)) dem++;
        }
        daThayDoi = false;
        return dem;
    }

    bool coTu(const string& w) const { return bang.co(w); }

    bool themTu(const string& w) {
        bool ok = bang.them(w);
        if (ok) daThayDoi = true;
        return ok;
    }

    bool ghiFile(const string& duongDan) {
        ofstream f(duongDan.c_str());
        if (!f) return false;
        vector<string> ds;
        bang.layTatCa(ds);
        sort(ds.begin(), ds.end());
        for (size_t i = 0; i < ds.size(); i++) f << ds[i] << "\n";
        daThayDoi = false;
        return true;
    }

    bool coThayDoi() const { return daThayDoi; }
    size_t soTu() const { return bang.kichThuoc(); }
};

// ---------- kiem tra chinh ta ----------
class KiemTraChinhTa {
    const TuDien& td;

public:
    KiemTraChinhTa(const TuDien& t) : td(t) {}

    // Tach doan van thanh cac tu (chu cai, cho phep dau ' o giua tu), doi sang chu thuong
    static vector<string> tachTu(const string& doan) {
        vector<string> kq;
        string cur;
        size_t n = doan.size();
        for (size_t i = 0; i < n; i++) {
            unsigned char c = doan[i];
            bool apostropheGiua = (c == '\'' && !cur.empty() && i + 1 < n && isalpha((unsigned char)doan[i + 1]));
            if (isalpha(c) || apostropheGiua) {
                cur += (char)tolower(c);
            } else if (!cur.empty()) {
                kq.push_back(cur);
                cur.clear();
            }
        }
        if (!cur.empty()) kq.push_back(cur);
        return kq;
    }

    // Tra ve cac tu sai chinh ta, moi tu chi xuat hien mot lan, theo thu tu gap
    vector<string> timTuSai(const string& doan) const {
        vector<string> sai;
        BangBam daGap;
        vector<string> cacTu = tachTu(doan);
        for (size_t i = 0; i < cacTu.size(); i++) {
            const string& w = cacTu[i];
            if (!td.coTu(w) && daGap.them(w)) sai.push_back(w);
        }
        return sai;
    }
};

string docDoan() {
    cout << "Nhap doan van (ket thuc bang mot dong trong):\n";
    string doan, dong;
    while (getline(cin, dong) && !chuanHoa(dong).empty()) doan += dong + "\n";
    return doan;
}

int main(int argc, char* argv[]) {
    string file = (argc > 1) ? argv[1] : "tu_dien.txt";
    TuDien td;
    int soNap = td.napTuFile(file);
    if (soNap < 0) {
        cout << "Khong mo duoc file tu dien: " << file << "\n";
        return 1;
    }
    cout << "Da nap " << soNap << " tu tu file " << file << "\n";

    string lenh;
    do {
        cout << "\n1. Kiem tra mot doan van\n0. Thoat\nChon: ";
        if (!getline(cin, lenh)) break;
        if (lenh != "1") continue;

        string doan = docDoan();
        KiemTraChinhTa kt(td);
        vector<string> sai = kt.timTuSai(doan);
        if (sai.empty()) {
            cout << "Khong phat hien tu sai chinh ta.\n";
            continue;
        }
        cout << "Cac tu bi bao sai chinh ta (" << sai.size() << "):\n";
        for (size_t i = 0; i < sai.size(); i++) cout << "  - " << sai[i] << "\n";

        for (size_t i = 0; i < sai.size(); i++) {
            cout << "Tu \"" << sai[i] << "\" co dung khong? Them vao tu dien (c/k)? ";
            string tl;
            if (!getline(cin, tl)) break;
            if (chuanHoa(tl) == "c") {
                td.themTu(sai[i]);
                cout << "  Da them.\n";
            }
        }
        if (td.coThayDoi()) {
            if (td.ghiFile(file)) cout << "Da ghi tu dien vao " << file << " (" << td.soTu() << " tu).\n";
            else cout << "Khong ghi duoc file.\n";
        }
    } while (lenh != "0");
    return 0;
}
