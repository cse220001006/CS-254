#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int low[N];
int disc[N];
int ap[N];
int Time = 0;
vector<pair<int,int>>bridges;

void dfs(int u, int p, vector<int>g[]) {
  int children = 0;
  low[u] = disc[u] = ++Time;
  for (int& v : g[u]) {
    if (v == p) continue;
    if (!disc[v]) {
      children++;
      dfs(v, u, g);
      if (disc[u] <= low[v]) ap[u] = 1;
      if (disc[u] < low[v]) bridges.push_back({u, v});
      low[u] = min(low[u], low[v]);
    } 
    else{
      low[u] = min(low[u], disc[v]);
    }
  }
  if(p == -1){
    ap[u] = children > 1;
  }
}

int main(){
    int n, e; cin >> n >> e;
    vector<int>g[n];
    while(e--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(disc[i] == 0){
            dfs(i, -1, g);
        }
    }
    cout << "Articulation points are: " << endl;
    for(int i = 0; i < n; i++){
        if(ap[i] == 1){
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "Bridges are: " << endl;
    for(auto p : bridges){
        cout << p.first << " " << p.second << endl;
    }
}