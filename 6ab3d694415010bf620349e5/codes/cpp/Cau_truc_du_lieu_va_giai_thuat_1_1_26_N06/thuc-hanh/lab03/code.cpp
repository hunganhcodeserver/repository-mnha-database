#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node{
public:
    T elem;
    Node<T>* left;
    Node<T>* right;

    Node(T x){
        elem = x;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class BST{
private:
    Node<T>* root;

public:
    BST(){
        root = nullptr;
    }

    Node<T>* insert(Node<T>* H, T x){
        if(H == nullptr){
            return new Node<T>(x);
        }

        if(x < H->elem){
            H->left = insert(H->left, x);
        }
        else if(x > H->elem){
            H->right = insert(H->right, x);
        }

        return H;
    }

    void insert(T x){
        root = insert(root, x);
    }

    Node<T>* find(Node<T>* H, T x){
        if(H == nullptr){
            return nullptr;
        }

        if(H->elem == x){
            return H;
        }

        if(x < H->elem){
            return find(H->left, x);
        }

        return find(H->right, x);
    }

    void search(T x){
        Node<T>* p = find(root, x);

        if(p != nullptr){
            cout << "Tim thay " << x << endl;
        }
        else{
            cout << "Khong tim thay " << x << endl;
        }
    }

    void inOrder(Node<T>* H){
        if(H == nullptr){
            return;
        }

        inOrder(H->left);
        cout << H->elem << " ";
        inOrder(H->right);
    }

    void inOrder(){
        inOrder(root);
        cout << endl;
    }

    T min(){
        Node<T>* p = root;

        while(p->left != nullptr){
            p = p->left;
        }

        return p->elem;
    }

    T max(){
        Node<T>* p = root;

        while(p->right != nullptr){
            p = p->right;
        }

        return p->elem;
    }

    T successor(T x){
        Node<T>* p = root;
        Node<T>* k = nullptr;

        while(p != nullptr){
            if(x < p->elem){
                k = p;
                p = p->left;
            }
            else{
                p = p->right;
            }
        }

        if(k != nullptr){
            return k->elem;
        }

        return -1;
    }

    T predecessor(T x){
        Node<T>* p = root;
        Node<T>* k = nullptr;

        while(p != nullptr){
            if(x > p->elem){
                k = p;
                p = p->right;
            }
            else{
                p = p->left;
            }
        }

        if(k != nullptr){
            return k->elem;
        }

        return -1;
    }

    int height(Node<T>* H){
        if(H == nullptr){
            return 0;
        }

        int trai = height(H->left);
        int phai = height(H->right);

        if(trai > phai){
            return trai + 1;
        }

        return phai + 1;
    }

    int height(){
        return height(root);
    }

    void xoa(Node<T>*& H, T x){
        if(H == nullptr){
            return;
        }

        if(x < H->elem){
            xoa(H->left, x);
        }
        else if(x > H->elem){
            xoa(H->right, x);
        }
        else{
            if(H->left == nullptr){
                Node<T>* p = H;
                H = H->right;
                delete p;
            }
            else if(H->right == nullptr){
                Node<T>* p = H;
                H = H->left;
                delete p;
            }
            else{
                Node<T>* p = H->right;

                while(p->left != nullptr){
                    p = p->left;
                }

                H->elem = p->elem;
                xoa(H->right, p->elem);
            }
        }
    }

    void erase(T x){
        xoa(root, x);
    }

    void show(Node<T>* H, int k){
        if(H == nullptr){
            return;
        }

        show(H->right, k + 1);

        for(int i = 0; i < k; i++){
            cout << "    ";
        }

        cout << H->elem << endl;

        show(H->left, k + 1);
    }

    void show(){
        show(root, 0);
    }
};

int main(){
    BST<int> T;

    T.insert(50);
    T.insert(30);
    T.insert(70);
    T.insert(20);
    T.insert(40);
    T.insert(60);
    T.insert(80);
    T.insert(35);

    cout << "Inorder: ";
    T.inOrder();

    cout << "Min = " << T.min() << endl;
    cout << "Max = " << T.max() << endl;

    int x;

    cout << "Nhap khoa can tim: ";
    cin >> x;

    T.search(x);

    cout << "Ke vi = " << T.successor(x) << endl;
    cout << "Tien nhiem = " << T.predecessor(x) << endl;

    cout << "Chieu cao = " << T.height() << endl;

    cout << "\nCau truc BST:\n";
    T.show();

    cout << "\nXoa nut la 20:\n";
    T.erase(20);
    T.inOrder();

    cout << "Xoa nut co 1 con 30:\n";
    T.erase(30);
    T.inOrder();

    cout << "Xoa nut co 2 con 50:\n";
    T.erase(50);
    T.inOrder();

    return 0;
}