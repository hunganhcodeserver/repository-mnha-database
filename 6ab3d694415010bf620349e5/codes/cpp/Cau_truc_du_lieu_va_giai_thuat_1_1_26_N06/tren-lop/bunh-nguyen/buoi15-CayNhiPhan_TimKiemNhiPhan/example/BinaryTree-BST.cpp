#include<iostream>
using namespace std;

template <class T>
class Node {
	public:
		T elem;
		Node<T>* left;
		Node<T>* right;

		Node(T x) {
			elem = x ;
			left = nullptr;
			right = nullptr;
		}

		int count(Node<T>*H, T x) {
			if(H == nullptr) {
				return 0;
			}

			int cnt = 0 ;
			if(H->elem == x) {
				cnt = 1
			}
			return cnt + count(H->left,x) + count(H->right,x);
		}

		//find
		Node<T>*find(Node<T>*H, T x) {
			if(H == nullptr) {
				return nullptr;
			}

			if(H->elem == x) {
				return H;
			}

			Node<T>*p =	find(H->left,x);
			if(p != nullptr) { //tim duoc node chua x trong cay con trai
				return p;
			}

			return find(H->right,x);
		}

		//Ap dung doi voi cay nhi phan tim kiem
		T*max(T x) {
			Node<T>* p =this ;
			while (p->right != nullptr) {
				p = p->right;
			}
			return &(p->elem);
		}

		Node<T>* insert(Node<T>*H, T x) {
			if(H == nullptr) {
				return new Node<T>(x);
			}

			if(x < H->elem) {
				H->left = insert(H->left,x);
			} else if(x > H->elem) {
				H->right = insert(H->right,x);
			}

			return H;//tra ve goc cua cay sau khi chen
		}
		void insert2(Node<T>*H, T x) {
			if(H == nullptr) {
				H = new Node<T>(x);
				return ;
			}

			if(x < H->elem) {
				H->left = insert(H->left,x);
			} else if(x > H->elem) {
				H->right = insert(H->right,x);
			}
		}

};
class BinaryTree {
	private:
		Node<T>* root;
		int n;
	public:
		BinaryTree() {
			root = nullptr;
			n = 0;
		}

		bool empty() {
			return root == nullptr;
		}

		//Duyet truoc - Goc - Trai - Phai
		void preOrder(Node<T>*p) {
			if(p == nullptr) {
				return;
			}

			cout<<p->elem<<" ";
			preOrder(p->left);
			preOrder(p->right);
		}
		//Duyet giua  - Trai - Goc  - Phai
		void inOrder(Node<T>* p) {
			if(p == nullptr) {
				return;
			}
			inOrder(p->left);
			cout<<p->elem<<" ";
			inOrder(p->right);
		}

		//Duyet Sau - Trai - Phai - Goc
		void postOrder(Node<T>* p) {
			if(p == nullptr) {
				return;
			}
			postOrder(p->left);
			postOrder(p->right);
			cout<<p->elem<<" ";
		}



		T*max(T x) {
			Node<T>* p =this ;
			while (p->right != nullptr) {
				p = p->right;
			}
			return &(p->elem);
		}

		void xoa(Node<T>*H,T x) {
			if(H == nullptr) {
				return;
			}
			if(x < H->elem) {
				xoa(H->left,x);
			} else if(x > H->elem) {
				xoa(H->right,x);
			} else {
				if(H->left == nullptr) { //khong co nut con trai
					Node<T>*p = H;
					H  = H->right;
					delete p;
				} else if (H->right ==nullptr) { //khong co nut con phai
					Node<T>*p = H;
					H =  H->left;
					delete p;
				} else { //co 2 nut con
					Node<T>*p = H->right;
					while(p->left != nullptr) {
						p = p->left;
					}
					H->elem = p->elem;
					xoa(H->right,p->elem);
				}
			}

		}
		void erase(T x) {
			xoa(root,x);
		}

};