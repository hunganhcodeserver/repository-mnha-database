#ifndef Node.cpp
#define Node.cpp
using namespace std;
template <class Element>
class Node {
	private:
		Element data;
		Node<Element>*next;

	public:
		//Ham tao
		Node(Element e) {
			data = e;
			next = nullptr;
		}
		//Tra ra dia chi cua node ke tiep
		Node<Element>* getNext() {
			return next;
		}
		//Tra ra giá tri
		Element getData() {
			return data;
		}

		//gan gia tri cho data
		void setData(Element e) {
			data = e;
		}
		//gan gia tri cho data
		void setNext(Node<Element>* p){
			next = p ;
		}
	
};
#endif

