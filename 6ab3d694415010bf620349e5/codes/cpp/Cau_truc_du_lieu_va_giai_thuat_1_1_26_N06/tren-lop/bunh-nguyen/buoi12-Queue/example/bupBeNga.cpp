#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n,x; 
	queue<int> q;
	cout<<"Nhap so luong bup be:";
	cin>>n;
	
	for(int i = 0 ; i  < n; i++){
		cout<<"Chieu cao bup be "<<i+1<<":";
		cin>>x;
		if(!q.empty() && q.front() - x >= 3){
			q.pop();//if dung 
		}
		q.push(x);//dua vao queue - if dung  hay  sai 
	}
	
	cout<<"So bup be it nhat:"<<q.size();
}