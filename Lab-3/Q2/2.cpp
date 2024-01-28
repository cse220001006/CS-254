#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N];

long long calc(int l, int m, int r){
    long long mx1 = 0, mx2 = 0;
    long long sum = 0;
    for(int i = m; i >= l; i--){
        sum += a[i];
        mx1 = max(mx1, sum);
    }
    sum = 0;
    for(int i = m+1; i <= r; i++){
        sum += a[i];
        mx2 = max(mx2, sum);
    }
    return mx1+mx2;
}

long long max_sum(int l, int r){
    if(l == r){
        return a[l];
    }
    int m = l + (r-l)/2;
    long long left = max_sum(l, m);
    long long right = max_sum(m+1, r);
    long long mid = calc(l, m, r);
    return max(left, max(right, mid));
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = max_sum(0, n-1);
    cout << ans << '\n';
}
