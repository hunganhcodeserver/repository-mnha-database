#ifndef untitled1.cpp
#define untitled1.cpp
using namespace std;

template <class Element>

class Node{
    private:
        Element data;
        Node <Element>* next;
    public:
        //Ham tao
        Node(Element e){
            data = e;
            next = nullptr;
        }
        //Tra ra dia chi cua node ke tiep
        Node<Element>* getNext(){
            return next;
        }
        //Tra ra gia tri
        Element getData(){
            return data;
        }
        //gan gia tri cho data
        void setData (Element e){
            data = e;
        }
        //gan gia tri cho data
        void setNext(Node<Element>* p){
            next = p;
        }
};

// int main() {
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     int a, b;
//     cout << "Nhap a, b: ";
//     cin >> a >> b;
//     cout << "Tong = " << a + b << endl;
//     return 0;
// }


#endif