#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T x) {
        data = x;
        next = nullptr;
    }
};

template <class T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void push(T x) {
        Node<T>* p = new Node<T>(x);
        p->next = topNode;
        topNode = p;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }
        Node<T>* p = topNode;
        topNode = topNode->next;
        delete p;
    }

    T top() {
        if (isEmpty()) {
            throw runtime_error("Stack rong!");
        }
        return topNode->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }
        Node<T>* p = topNode;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

bool isValidParentheses(const string& expr) {
    Stack<char> st;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.isEmpty()) return false;
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main() {
    Stack<int> st;
    int data[] = {10, 20, 30, 40, 50};
    for (int x : data) {
        st.push(x);
    }

    cout << "Cac phan tu trong Stack (tu dinh xuong day): ";
    st.display();

    cout << "Phan tu o dinh (top): " << st.top() << endl;
    st.pop();
    cout << "Sau khi pop(), cac phan tu con lai: ";
    st.display();

    cout << "Stack co rong khong? " << (st.isEmpty() ? "Co" : "Khong") << endl;

    string expr1 = "({[]})";
    string expr2 = "([)]";
    cout << "Bieu thuc " << expr1 << ": "
         << (isValidParentheses(expr1) ? "Hop le" : "Khong hop le") << endl;
    cout << "Bieu thuc " << expr2 << ": "
         << (isValidParentheses(expr2) ? "Hop le" : "Khong hop le") << endl;

    return 0;
}