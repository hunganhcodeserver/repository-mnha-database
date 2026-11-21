#include <bits/stdc++.h>
using namespace std;

template<class T>
class Vector {
    private:
        int cap; //so phan tu toi da
        int n; //so phan tu hien tai(size)
        T *v; //mang dong
    public:
    Vector(){
        cap = 0;
        n = 0;
        v = NULL;
    }
    
    //tao vector co n phan tu
    Vector(int size){
        n = size;
        cap = size;
        if(cap > 0){
            v = new T[cap];
        }
        else{ //cap = 0
            v = nullptr;
        }
    }
    
    //tao vector co k phan tu, tat ca gia tri = k
    Vector(int k, T x){
        n = k;
        cap = k;
        if(cap > 0){
            v = new T[cap];
        }
    }
    
    
}
