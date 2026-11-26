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
        int h = 0, k; //su dung hoi void high
        
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
            if(k > h){ //cap nhat chieu cao lon nhat
                h = k;
            }
            for(Node<T>*p : H->child){
                k++;
                high(p);
                k--;
            }
        }
        
        int high2(Node<T>*H){
            if(H == nullptr){
                return -1;
            }
            int h = -1;
            for(Node<T>*p : H->child){
                int k = high2(p);
                if(k > h){
                    h = k;
                }
            }
            return h+1;
        }
        
        Node<T>*find(Node<T>*H,T x){
            if(H == nullptr){
                return nullptr;
            }
            if(H->elem == x){
                return ;
            }
            for(Node<T>*p : H->child){
                Node<T>* k = find(p,x); //luu dia chi node tim duoc
                if(k != nullptr){
                    return k;
                }
            }
            return nullptr;
        }
        
        void insert(Node<T>*H, T x, Node<T> *p){
            if(H == nullptr || p == nullptr){
                return;
            }
            Node<T>*k = find (H,x);
            if(k!=nullptr){
                k->child.push_back(p);
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
