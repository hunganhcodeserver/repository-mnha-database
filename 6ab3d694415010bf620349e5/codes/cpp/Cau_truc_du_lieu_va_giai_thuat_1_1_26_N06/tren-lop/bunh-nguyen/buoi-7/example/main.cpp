#include<iostream>
#include "vector.cpp"

using namespace std;

int main() {

	Vector <int> vt;
	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(30);
	cout<<"Vector:";
	for(int i = 0 ; i < vt.size();i++){
		cout<<vt[i]<<" "; 
	}
	cout<<"\nSize:"<<vt.size();
	cout<<"\nBack:"<<vt.back();
}