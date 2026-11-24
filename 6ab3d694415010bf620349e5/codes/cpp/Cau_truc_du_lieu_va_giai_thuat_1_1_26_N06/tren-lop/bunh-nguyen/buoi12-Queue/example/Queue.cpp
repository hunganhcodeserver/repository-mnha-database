#include<iostream>
using namespace std;

template<class T>
class Queue {
	private :
		T a[100];//chua cac phan tu - doi tuong
		int F;//chi vi tri cua phan tu dau tien
		int L; //Chi o trong tiep theo de them phan tu
		int num;//so phan tu co trong mang
	public :
		Queue() {
			F=L=num = 0;
		}
		//size
		int	size() {
			return num;
		}
		
		bool isEmpty(){
			return num==0;
		}
		//lay ra gia tri dau tien
		T& front(){
			return a[F];
		}
		//Lay ra gia tri cuoi cung 
		T& back(){
			return a[(L-1 +100 ) %100];
			//	[(L - 1 + N ) % N ]	
//			if(L ==0){
//				return a[n-1];
//			}else{
//				return a[L - 1];
//			}
		}
		//them vao cuoi 
		void push(T x){
			if(num == 100){
				cout<<"Mang day";
				return;
			}
			a[L] = x;
			L = (L +1) %100; // (L + 1) %N
			num++;
		}
		//bo phan tu dau 
		void pop(){
			if(isEmpty()){
				cout<<"Mang rong";
				return ;
			}
			
			F = (F + 1)%100; // (F+1)%N 
		}
	
	
	
	
	
};