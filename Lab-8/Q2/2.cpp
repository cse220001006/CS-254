#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int graph[N][N][2];
long long dp[1<<N][N][2];

long long minCost(int n, int m, int mask, int prev, int col){
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if(dp[mask][prev][col == 1] != 0) {
        return dp[mask][prev][col == 1];
    }
    long long ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++){
            if(graph[prev][i][j] && !(mask & (1 << i)) && (j != col)){
                ans = min(graph[prev][i][j] + minCost(n,m,mask|(1<<i),i,j), ans);
            }
        }
    }
    return dp[mask][prev][col == 1] = ans;
}

int main(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        int cost; cin >> cost;
        char color; cin >> color;
        int col = 0;
        if(color == 'G') col = 1;
        graph[a][b][col] = cost;
        graph[b][a][col] = cost;
    }
    long long ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, minCost(n, m, 1 << i, i, 2));
    }
    cout << ans << '\n';
    
    return 0;
}