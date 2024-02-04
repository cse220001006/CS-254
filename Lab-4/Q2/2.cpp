#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N], b[N];

int main() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    double ans = 0;
    int k = (n+m+1)/2;
    int i = 0, j = 0;
    while(i+j+2 <= k){
        if(i >= n){
            j++;
        }
        else if(j >= m){
            i++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    if(i >= n){
        ans += b[j];
        if((n+m)%2 == 0){
            j++;
            ans += b[j];
            ans /= 2;
        }
    }
    else if(j >= m){
        ans += a[i];
        if((n+m)%2 == 0){
            i++;
            ans += a[i];
            ans /= 2;
        }
    }
    else{
        if(a[i] < b[j]){
            ans += a[i];
            i++;
        }
        else{
            ans += b[j];
            j++;
        }
        if((n+m)%2 == 0){
            if(i >= n){
                ans += b[j];
                ans /= 2;
            }
            else if(j >= m){
                ans += a[i];
                ans /= 2;
            }
            else{
                ans += min(a[i], b[j]);
                ans /= 2;
            }
        }
    }
    cout << "Median element is: " << ans << endl;
    return 0;
}
