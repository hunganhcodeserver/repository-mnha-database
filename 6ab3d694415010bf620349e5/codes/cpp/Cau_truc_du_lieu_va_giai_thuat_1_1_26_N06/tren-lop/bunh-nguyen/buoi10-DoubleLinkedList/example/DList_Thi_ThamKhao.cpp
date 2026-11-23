
#include <iostream>
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
        prev = next = nullptr;
    }
};

// Lop mau Dlist
template <class T>
class Dlist {
private:
    int n;
    Node<T>* Head;
    Node<T>* Trail;

public:
    Dlist() {
        n = 0;
        Head = Trail = nullptr;
    }
    void push_front(T x);
    void erase(T x);
};

// Them phan tu vao dau
template <class T>
void Dlist<T>::push_front(T x) {
    Node<T>* p = new Node<T>(x);

    p->next = Head;

    if (Head != nullptr)
        Head->prev = p;
    else
        Trail = p;

    Head = p;
    n++;
}

// Xoa phan tu co gia tri x
template <class T>
void Dlist<T>::erase(T x) {
    Node<T>* p = Head;

    // Tim node chua x
    while (p != nullptr && p->elem != x)
        p = p->next;

    if (p == nullptr) return;

    // Noi lai lien ket phia truoc
    if (p->prev != nullptr)
        p->prev->next = p->next;
    else
        Head = p->next;

    // Noi lai lien ket phia sau
    if (p->next != nullptr)
        p->next->prev = p->prev;
    else
        Trail = p->prev;

    delete p;
    n--;
}

