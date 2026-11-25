#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,x;
    queue<int> q;
    cout<<"Nhap so luong bup be: ";
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cout << "Chieu cao bup be " << i+1;
        cin >>x;
        if(!q.empty() && q.front() - x >= 3){
            q.pop();
        }
        q.push(x);
    }
    return 0;
}
