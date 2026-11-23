#include <bits/stdc++.h>
using namespace std;

template <class T>

//Lop mau Node
class Node{
    public:
        T elem;
        Node<T>* prev;
        Node<T>* next;
        Node(T x){
            elem = x;
            prev = nullptr;
            next = nullptr;
        }
};

//Lop mau DLIST
template <class T>
class DList{
    private:
        int n;
        Node<T>* Head;
        Node<T>* Trail;
    public:
        
        DList(){
            n = 0;
            Head = nullptr;
            Trail = nullptr;
        }
        //Destructor
        
        //size()
        int size(){
            return n;
        }
        
        //empty
        bool empty(){
            return n == 0;
        }
        
        //lay ra gia tri dau tien
        T& front(){
            return Head->elem;
        }
        
        //lay ra gia tri cuoi
        T& back(){
            return Trail->elem;
        }
        
        void push_front(T x);
        
        void push_back(T x);
};

void DList<T>::push_front(T x){
    Node<T*> newNode = new Node<T>(x);
    
    //Neu danh sach rong
    if(empty()){
        Head = newNode;
        Trail = newNode;
    }else{
        // =========CHU Y KHI TAO NODE MOI ROI NHET VAO DAU=========
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
    n++;
}

void DList<T>::push_back(T x){
    Node<T>* newNode = new Node<T>(x);
    //Neu danh sach rong
    if(empty()){
        Head = newNode;
        Trail = newNode;
    } else {
        newNode->prev = Trail;
        trail->next = newNode;
        Trail = newNode;
    }
    n++;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong = " << a + b << endl;
    return 0;
}
