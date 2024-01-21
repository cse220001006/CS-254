#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long mn1 = 1e18, mn2 = 1e18;
    for(int i = 0; i < n; i++){
        long long x; cin >> x;
        if(x <= mn1){
            mn2 = mn1;
            mn1 = x;
        }
        else if(x <= mn2){
            mn2 = x;
        }
    }
    cout << mn1 << " " << mn2 << '\n';
}