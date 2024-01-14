#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long mx1 = -1e18, mx2 = -1e18;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        if(x >= mx1){
            mx2 = mx1;
            mx1 = x;
        }
        else if(x >= mx2){
            mx2 = x;
        }
    }
    cout << mx1+mx2 << '\n';
}