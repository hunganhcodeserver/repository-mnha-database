#include<iostream>
using namespace std;

// Lop mau Node
template <class T>
class Node {
	public:
		T elem;
		Node<T>* prev;
		Node<T>* next;

		Node(T x) {
			elem = x;
			prev = nullptr;
			next = nullptr;
		}

};

//Lop mau DLIST
template <class T>
class Dlist {
	private:
		int n;
		Node<T>* Head;
		Node<T>* Trail;

	public:

		Dlist() {
			n = 0;
			Head = nullptr;
			Trail = nullptr;
		}

		//size
		int size() {
			return n;
		}

		//empty
		bool empty() {
			return n==0;
		}
		//Lay ra gia tri dau tien
		T&	front() {
			return Head->elem;
		}

		//Lay ra gia tri cuoi
		T& back() {
			return Trail->elem;
		}

		void push_front(T x);


		void push_back(T x) {
			Node<T>*newNode = new Node<T>(x);

			if(empty()) {
				Head = newNode;
				Trail = newNode;
			} else {
				newNode->prev = Trail;
				Trail->next = newNode;
				Trail = newNode;
			}
			n++;
		}

		//Xoa phan tu dau
		void pop_front() {
			if(empty()) {
				return;
			}

			Node<T>*temp = Head;
			Head = Head->next;
			//truong hop list chi co 1 node
			if(Head != nullptr) {
				Head->prev = nullptr;
			} else {
				Trail = nullptr;
			}
			delete temp;
			n--;
		}
		void print() {

			Node<T>* current = Head;

			while (current != nullptr) {

				cout << current->elem << " ";

				current = current->next;
			}

			cout << endl;
		}
		//xoa phan tu cuoi
		void pop_back() {

			if (empty()) {
				return;
			}

			Node<T>* temp = Trail;

			Trail = Trail->prev;

			if (Trail != nullptr) {
				Trail->next = nullptr;
			} else {
				Head = nullptr;
			}

			delete temp;
			n--;
		}
		void erase(T x);

};
template <class T>
void Dlist<T>::push_front(T x) {

	Node<T>* newNode = new Node<T>(x);
//Neu danh sach rong
	if(empty()) {
		Head = newNode;
		Trail = newNode;
	} else {
		newNode->next = Head;
		Head->prev = newNode;
		Head = newNode;
	}
	n++;
}

template <class T>
void Dlist<T>::erase(T x) {
	if(empty()) {
		return;
	}

	Node<T>* current =Head ;
	//Tim Node co gia tri x - Duyet
	while(current != nullptr  && current->elem != x) {
		current = current->next; // A Co B Khong
	}

	//Khong tim thay x
	if (current == nullptr) {
		return;
	}

	//Neu thay x o dau
	if (current == Head) {
		pop_front(); //xoa phan tu dau
		return;
	}
	//Neu thay x o cuoi
	if(current == Trail) {
		pop_back();
		return;
	}
	current->prev->next  = current->next;
	current->next->prev  = current->prev;

	delete current ;
	n--;
}

int main() {
	Dlist<int> ds;

	ds.push_front(10);
	ds.push_front(20);
	ds.push_front(20);

	ds.erase(50);
}





