#include<iostream>
#include "Node.cpp"
using namespace std;

template <class Element>
class SingleLinkedList {
	private:
		Node<Element>*head;//node dau tien
		Node<Element>*tail;//node cuoi cung
		int n; //so luong phan tu hien co trong danh sach
	public:
		SingleLinkedList() {
			head = nullptr;
			tail = nullptr;
			n =0;
		}

//		~SingleLinkedList() {
//			clear();
//		}

		//capacity
		//Tra ve so luong phan tu
		int	size() {
			return n;
		}
		//kiem tram danh sach rong
		bool empty() {
			return n==0;
		}

		//Them phan tu vao dau
		void push_front(Element e) {
			//tao 1 node moi
			Node<Element>* newNode =  new Node<Element>(e);

			//con tro tro toi node head
			newNode->setNext(head);
			//cho head tro den nodeNew
			head = newNode ;

			//Danh sach rong
			if(empty()) { // tail == nulptr
				tail = newNode;
			}
			n++;
		}
		//xoa phan tu o dau
		void pop_front() {
			//Kiem tra danh rong khong
			if(empty()) {
				return;
			}
			Node<Element>* temp = head;

			head = head->getNext();

			delete temp;

			n--;

			if(n==0) {
				tail =nullptr;
			}
		}

		//Them phan tu vao cuoi
		void push_back(Element e) {
			Node<Element>* newNode =  new Node<Element>(e);
			
			if(empty()){
				head = newNode;
				tail = newNode;
			}else{
				tail->setNext(newNode)
				tail = newNode;
			}
			n++;
		}
		
		//Xoa phan tu cuoi 
		void pop_back(){
			if(empty()){
				return 
			}
			//Co 1 node
			if(head == tail){
				delete head;
				head = nullptr;
				tail = nullptr;
				
				n--;
				return 
			}
			Node<Element>* p = head;
			//tim node dung truoc tail 
			while(p->getNext() !=tail ){
				p = p->next();
			}
		
			delete tail ;
			tail = p; 
			tail->setNext(nullptr) ;
			n--;
		}










};