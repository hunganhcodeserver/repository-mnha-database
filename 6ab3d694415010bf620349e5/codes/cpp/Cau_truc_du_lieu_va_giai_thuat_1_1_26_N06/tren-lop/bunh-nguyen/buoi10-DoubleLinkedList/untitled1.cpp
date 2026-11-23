#include <bits/stdc++.h>
#include "untitled1.cpp"
using namespace std;

template <class Element>;

class SingleLinkedList{
    public:
        class Iterator{
            private:
                Node<Element>* current;
            public:
                //ham tao
                Iterator(Node<Element>*p = nullptr){
                    current = p;
                }
                //lay ra gia tri hien tai
                Element operator*(){
                    return current->getData();
                }
                
                //di chuyen den node tiep theo
                Iterator& operator++(){
                    current = current->getNext();
                    return *this;
                }
        }
    private:
        Node<Element>*head; //node dau tien
        Node<Element>*tail; //node cuoi cung
        int n; //so luong phan tu hien co trong danh sach
    public:
        SingleLinkedList(){
            head = nullptr;
            tail = nullptr;
            n = 0;
        }
        ~SingleLinkedList(){
            clear();
        }
        
        //capacity
        //Tra ve so luong phan tu
        size(){
            return n;
        }
        //Kiem tra danh sach rong
        bool empty(){
            return n == 0;
        }
        
        //Them phan tu vao dau
        void push_front(Element e){
            //tao 1 node moi
            Node<Element>* newNode = new Node<Element>(e);
            
            //con tro tro toi node head
            newNode->setNext(head);
            //cho head tro toi nodeNew
            head = newNode;
            //Danh sach rong
            if(empty()){ // tail == nullptr
                tail = newNode;
            }
            n++;
        }
        
        //Xoa phan tu dau tien
        void pop_front(){
            //kiem tra danh sach rong
            if(empty()){
                return ;
            }
            Node<Element>* temp = head;
            head = head->getNext();
            delete temp;
            n--;
            if(n==0){
                tail = nullptr;
            }
        }
        
        //Them phan tu vao cuoi
        void push_back(Element e){
            //tao 1 node moi
            Node<Element>* newNode = new Node<Element>(e);
            
            if(empty()){
                head = newNode;
                tail = newNode;
            }else{
                tail->setNext(newNode);
                tail = newNode;
            }
            n++
        }
        
        //Xoa phan tu cuoi
        void pop_back(){
            if(empty()){
                return ;
            }
            //co 1 node
            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
                n--;
                return ;
            }
            Node<Element>* p = head;
            
            //tim node dung truoc tail
            while(p->getNext()!= tail){
                p = p->getNext();
            }
            delete tail;
            tail = p;
            tail->getNext(nullptr);
            n--;
        }
        //chen phan tu vao vi tri pos
        insert(int pos, Element e){
            if(pos<0 || pos > n){
                return ;
            }
            
            //chen vao dau
            if(pos == 0){
                push_front(e);
                return ;
            }
            
            //chen vao cuoi
            if(pos == n){
                push_back(e);
                return ;
            }
            
            Node<Element>* newNode = new Node<Element>(e);
            Node<Element>*  current = head;
            //tim node dung truoc vi tri pos
            
            for(int i = 0; i < pos; i++){
                current = current->getNext();
            }
            //Chu y thu tu
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            n++;
        }
        
        //xoa vi tri pos
        void erase(int pos){
            if(pos<0 || pos>n){
                return ;
            }
            
            if(pos == 0){
                pop_front();
                return ;
            }
            if(pop == n-1){
                pop_back();
                return ;
            }
            
            Node<Element>*current = head;
            
            //tim node dung truoc node can xoa
            for(int i = 0; i < pos - 1; i++){
                current = current->getNext();
            }
            
            Node<Element>* temp = current->getNext();
            //noi node truoc voi node sau
            current->setNext(temp->getNext());
            
            delete temp;
            n--;
        }
    
    // xoa phan tu co vi tri x
    void remove(Element x){
        if(empty()){
            return;
        }
        //x nam o dau
        if(head->getData() == x){
            pop_front();
            return;
        }
        Node<Element>* current = head;
        
        //Tim node dung truoc node co gia tri x
        while(current->getNext != nullptr && current->getNext()->getData() != x){
            current = current->getNext();
        }
        
        //Khong tim thay x
        if(current->getNext() == nullptr){
            return ;
        }
        
        //Neu x o cuoi
        if(current->getNext() == tail){
            pop_back();
            return;
        }
        
        //Xoa node o giua
        Node<Element>*temp = current->getNext();
        current->setNext(temp->getNext());
        delete temp;
        n--;
    }
    
    //cap nhat gia tri tai vi tri pos
    void update(int pos, Element e){
        if(pos<0 || pos >= n){
            return;
        }
        Node<Element>* current = head;
        //duyet den vi tri pos
        for(int i = 0; i < pos; i++){
            current = current->getNext();
        }
        current->setData(e);
    }
    
    //xoa toan bo danh sach
    void clear(){
        while(head != nullptr){
            Node<Element>*temp = head;
            head = head->getNext();
            delete head;
        }
        tail = nullptr;
        n = 0;
    }
    
    void print(){
        Node<Element>* p = head;
        while(p != nullptr){
            cout << p->getNext() << " ";
            p = p->getNext();
        }
        cout << "List: ";
        list.print();
    }
};
