#include <bits/stdc++.h>
using namespace std;

template <class T>

class Node{ //dai dien cho 1 node
    T elem;
    vector<Node<T>*> child;
    
    Node(T x){
        elem = x;
    }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong = " << a + b << endl;
    return 0;
}
