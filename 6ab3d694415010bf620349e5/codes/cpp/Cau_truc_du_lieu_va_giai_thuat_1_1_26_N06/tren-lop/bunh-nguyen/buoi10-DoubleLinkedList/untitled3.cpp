#include <bits/stdc++.h>
using namespace std;

template <class T>

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
