#include <bits/stdc++.h>
using namespace std;

template <class T>

class Node{ //dai dien cho 1 node
    public:
        T elem;
        vector<Node<T>*> child; //vector chua dia chi cac Node con
        
        Node(T x){
            elem = x;
        }
};

template<class T>

class Tree{
    private:
        Node<T>* root; //nut goc
    public:
        //khoi tao
        Tree(){
            root = nullptr;
        }
        
        //lay node goc
        Node<T>* getRoot(){
            return root;
        }
        
        //lay tong so node
        int size(Node<T>* H){
            if(H == nullptr){
                return 0;
            }
            int dem = 1;
            for(int i = 0; i < H->child.size(); i++){
                dem += size(H->child[i]);
            }
            return dem;
        }
        
        //Duyet truoc: Goc - trai - phai
       
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
