#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+50;
int matrix[N][N];
int n, m;

bool check(int i, int j){
    return (i >= 0 && i < n) && (j >= 0 && j < m);
}

void bfs(int i, int j, int &k){
    queue<pair<int, int>>q;
    q.push({i, j});
    while(q.size() > 0){
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        k++;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int xx = x+i;
                int yy = y+j;
                if(check(xx, yy) && matrix[xx][yy] == 1){
                    matrix[xx][yy] = 0;
                    q.push({xx, yy});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                continue;
            }
            matrix[i][j] = 0;
            int k = 0;
            bfs(i, j, k);
            ans = max(ans, k);
        }
    }
    cout << ans << endl;
}
