#include<iostream>
using namespace std;

template <class T>
class Node {
public:
		T data;
		Node<T>* next ;

		Node(T x) {
			data = x ;
			next = nullptr;
		}
};

template <class T>
class Stack {
		Node<T>* top;
public:
		Stack() {
			top = nullptr;
		}

		~Stack() {
			while(top != nullptr){
				pop();
			}
		}

		bool isEmpty() {
			return top == nullptr;
		}

		//Them 1 node vao dau - giong voi singleLinkedlist
		void push(T x) {
			Node<T>*p = new Node<T>(x);
			p->next = top;
			top = p;
		}
//xoa phan tu tren cung
		void pop() {
			if(isEmpty()) {
				cout<<"stack rong";
				return;
			}
			Node<T> *p = top;
			top  = top->next ;
			delete p;
		}
//lay gia tri phan tu top
		T&	peek() {
			if(isEmpty()) {
				cout<<"stack rong";
				return T();
			}
			return top->data;
		}

		void printf(){
			Node<T>*p = top;
			while (p != nullptr){
				cout<<p->data<<" ";
				p = p->next;
			}
			cout<<endl ;
		}
};
int main(){
	Stack<int> st;
	st.push(5);
	st.push(3);
	st.printf();
}




