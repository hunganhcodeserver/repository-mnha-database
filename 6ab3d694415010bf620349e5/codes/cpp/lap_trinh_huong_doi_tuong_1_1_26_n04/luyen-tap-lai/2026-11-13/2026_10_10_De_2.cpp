#include<bits/stdc++.h>

using namespace std;

class cty{
	private:
		string tenCty;
		int ntl;
	public:
		cty(){
			tenCty = "";
			ntl = 0;
		}
		void nhap(){
			cout << "Nhap ten cong ty: ";
			getline(cin >> ws, tenCty);
			cout << "Nhap nam thanh lap: ";
			cin >> ntl;
		}
		void xuat(){
			cout << "Cong ty: " << tenCty << ", Nam thanh lap: " << ntl;
		}
		int getNam(){
			return ntl;
		}
};

class ctypm : public cty{
	private:
		int sltv;
	public:	
		int getSltv(){
			return sltv;
		}
		void nhap(){
			cty::nhap();
			cout << "Nhap so lap trinh vien: ";
			cin >> sltv;
		}
		void xuat(){
			cty::xuat();
			cout << ", So lap trinh vien: " << sltv << endl;
		}
};

class ctyvt : public cty{
	private:
		int soto;
	public:
		int getSoto(){
			return soto;
		}
		void nhap(){
			cty::nhap();
			cout << "Nhap so o to: ";
			cin >> soto;
		}
		void xuat(){
			cty::xuat();
			cout << ", So o to: " << soto << endl;
		}
};

void xepDK(vector<ctypm*> &cpm, vector<ctyvt*> &cvt, int n, int m){
	auto cmp = [](auto *a, auto *b){
		return a->getNam() < b->getNam();
	};
	sort(cpm.begin(), cpm.end(), cmp);
	sort(cvt.begin(), cvt.end(), cmp);
	cout << "Cong ty phan mem thanh lap sau nam 2000:\n";
	for(int i = 0; i < n; i++){
		if(cpm[i]->getNam() > 2000 && cpm[i]->getSltv() > 20) cpm[i]->xuat();
	}
	cout << "Cong ty van tai thanh lap truoc nam 2000:\n";
	for(int i = 0; i < m; i++){
		if(cvt[i]->getNam() < 2000 && cvt[i]->getSoto() <= 10) cvt[i]->xuat();
	}
}

int main(){
	int n, m;
	cout << "Nhap so cong ty phan mem: n = ";
	cin >> n;
	cout << "Nhap so cong ty van tai: m = ";
	cin >> m;
	vector<ctypm*> cpm(n);
	vector<ctyvt*> cvt(m);
	for(int i = 0; i < n; i++){
		cpm[i] = new ctypm();
		cout << "Nhap cong ty phan mem thu " << i + 1 << ":\n";
		cpm[i]->nhap();
	}
	for(int i = 0; i < m; i++){
		cvt[i] = new ctyvt();
		cout << "Nhap cong ty van tai thu " << i + 1 << ":\n";
		cvt[i]->nhap();
	}
	cout << "\n===================XUAT===================\n";
	for(int i = 0; i < n; i++){
		cout << "Cong ty phan mem thu " << i + 1 << ":\n";
		cpm[i]->xuat();
	}
	for(int i = 0; i < m; i++){
		cout << "Cong ty van tai thu " << i + 1 << ":\n";
		cvt[i]->xuat();
	}
	xepDK(cpm, cvt, n, m);
	for(int i = 0; i < n; i++) delete cpm[i];
	for(int i = 0; i < m; i++) delete cvt[i];
	return 0;
}

