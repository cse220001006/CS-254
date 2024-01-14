#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
int w[N], val[N];

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    int W; cin >> W;
    vector<long long>dp(W+1);
    for(int i = 0; i < n; i++){
        for(int j = W; j >= 0; j--){
            if(w[i]+j <= W){
                dp[w[i]+j] = max(dp[w[i]+j], dp[j]+val[i]);
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i <= W; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}