#include <bits/stdc++.h>
using namespace std;


    
template <class T>

class Node{
    T data;
    Node<T>* next;
    Node(T x){
        data = x;
        next = nullptr;
    }
};

template <class T>
class Stack{
    Node<T>* top;
    
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        
    }
    bool isEmpty(){
        return top == nullptr;
    }
    
    //Them 1 node vao
    void push(T x){
        Node<T>* p = new Node<T>(x);
    }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int a, b;
    // cout << "Nhap a, b: ";
    // cin >> a >> b;
    // cout << "Tong = " << a + b << endl;
    
    return 0;
}


