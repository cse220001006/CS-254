#include <bits/stdc++.h>
using namespace std;

const int V = 5;

bool check(int G[][V], int src, int color[]){
    color[src] = 1;
    queue <int> q;
    q.push(src);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; ++v){
            if (G[u][v] && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (G[u][v] && color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int G[][V] = {{0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            G[i][j] = 1-G[i][j];
            if(i == j){
                G[i][j] = 0;
            }
        }
    }
    bool f = 1;
    int color[V];
    for (int i = 0; i < V; i++){
        color[i] = -1;
    }
    for (int i = 0; i < V; i++){
        if (color[i] == -1){
            if (check(G, i, color) == false){
                f = 0;
                break;
            }
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}
