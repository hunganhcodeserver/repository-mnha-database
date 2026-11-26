#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Node { //dai dien cho 1 node
	public:
		T elem ;
		vetor<Node<T>*> child ; //vector chua dia chi cac Node con

		Node(T x ) {
			elem = x;
		}
};

template<class T>
class Tree {
	private:
		Node<T>* root;//nut goc
		
	public:
		//khoi tao
		Tree() {
			root = nullptr;
		}
	//lay node goc 
		Node<T>* getRoot() {
			return root;
		}
			
};
