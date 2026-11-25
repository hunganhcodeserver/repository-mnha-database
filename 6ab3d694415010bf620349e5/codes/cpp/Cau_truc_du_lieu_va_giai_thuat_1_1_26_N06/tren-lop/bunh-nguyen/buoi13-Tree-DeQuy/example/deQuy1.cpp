#include<iostream>
using namespace std;

void dayGiam(int n) {
	if(n == 0) { // dieu kien dung
		return;
	}
	cout<<n<<" ";
	dayGiam(n-1); //loi goi de quy
}

void dayTang (int n) {
	if(n == 0) { // dieu kien dung
		return;//khi ket thu
	}
	dayTang(n-1);//loi goi de quy
	cout<<n<<" ";

}

int sum (int n) {
	if(n==0) {
		return 0;//ket thuc
	}
	return n + sum(n-1);
}
int main() {

	dayTang(3);
	cout<<	sum(5);
}