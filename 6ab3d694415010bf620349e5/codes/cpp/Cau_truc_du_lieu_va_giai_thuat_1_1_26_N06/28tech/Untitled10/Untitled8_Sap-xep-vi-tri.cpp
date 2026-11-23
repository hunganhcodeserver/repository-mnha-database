#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    freopen("Untitled8.cpp", "r", stdin); 
    int n; cin >> n;
    string a[n+1];
    for(int i = 0; i < n; i++){
    	cin >> a[i];
	}
	sort(a, a+n);
	do{
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}while(next_permutation(a, a+n));
}