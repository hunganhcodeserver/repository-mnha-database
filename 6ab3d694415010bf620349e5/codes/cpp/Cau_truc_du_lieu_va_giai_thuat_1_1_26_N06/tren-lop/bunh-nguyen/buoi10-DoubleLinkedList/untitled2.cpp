#include <bits/stdc++.h>
#include "untitled1.cpp"

using namespace std;



int main() {
    SingleLinkedList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    cout << "List: ";
    cout << "---Sau khi xoa---" << endl;
    list.remove(30);
    list.print();
    return 0;
}
