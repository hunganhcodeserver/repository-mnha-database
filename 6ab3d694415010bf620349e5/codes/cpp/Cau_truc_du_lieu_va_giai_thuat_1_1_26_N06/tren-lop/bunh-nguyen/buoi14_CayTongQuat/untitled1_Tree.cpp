#include <bits/stdc++.h>
using namespace std;

// template <class T>

// class Node{ //dai dien cho 1 node
//     public:
//         T elem;
//         vector<Node<T>*> child; //vector chua dia chi cac Node con
        
//         Node(T x){
//             elem = x;
//         }
// };





//==========================================
//==================DI THI==================
//==========================================
//
//=================*) Luu y: chua de thi nho dung kieu day het=================
template <class T>

class Node{ //dai dien cho 1 node
    public:
        T elem;
        vector<Node<T>*> child; //vector chua dia chi cac Node con
//        int dem = 0; //su dung khi de hoi void count(...)
        Node(T x){
            elem = x;
        }
        int count(Node<T>* H, T x){
            if(H == nullptr){
                return 0;
            }
            int dem = 0;
            if(H->elem == x){
                dem++;
            }
            for(Node<T> *p : H->child){
                dem += count(p, x);
            }
            return dem;
        }
        // void count2(Node<T>* H, T x){
        //     if(H == nullptr){
        //         return 0;
        //     }
        //     if(H->elem == x){
        //         dem++;
        //     }
        //     for(Node<T> *p : H->child){
        //         count(p, x);
        //     }
        // }
        void high(Node<T>* H){
            if(H == nullptr){
                return ;
            }
        }
};
//==========================================
//==========================================
//==========================================






// template<class T>

// class Tree{
//     private:
//         Node<T>* root; //nut goc
//     public:
//         //khoi tao
//         Tree(){
//             root = nullptr;
//         }
        
//         //lay node goc
//         Node<T>* getRoot(){
//             return root;
//         }
        
//         //lay tong so node
//         int size(Node<T>* H){
//             if(H == nullptr){
//                 return 0;
//             }
//             int dem = 1;
//             for(int i = 0; i < H->child.size(); i++){
//                 dem += size(H->child[i]);
//             }
//             return dem;
//         }
        
//         //Duyet truoc: Goc - trai - phai
//         void preOrder(Node<T>* H){
//             if(H == nullptr){
//                return;
//             }
//             cout << H->elem << " ";
            
//             for(Node<T>* p : H->child){
//                 preOder(p);
//             }
//         }
        
//         //Duyet sau: Trai - phai - goc
//         void postOrder(Node<T>* H){
//             if(H == nullptr){
//                return;
//             }
//             for(Node<T>* p : H->child){
//                 postOrder(p);
//             }
//             cout << H->elem << " ";
//         }
        
//         //dem tat ca cac Node cua cay H chua x
//         int count(Node<T>* H, T x){
//             if(H == nullptr){
//                 return 0;
//             }
//             int dem = 0;
//             if(H->elem == x){
//                 dem++;
//             }
//             for(Node<T> *p : H->child){
//                 dem += count(p, x);
//             }
//             return dem;
//         }
// };

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "Tong = " << a + b << endl;
    return 0;
}
