#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, e; cin >> n >> e;
    vector<int>g[n];
    vector<int>indeg(n);
    vector<int>dis(n);
    while(e--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<int>q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    int mx = 0;
    while(q.size() > 0){
        int u = q.front();
        q.pop();
        mx = max(mx, dis[u]);
        for(auto v : g[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
            dis[v] = max(dis[v], dis[u]+1);
        }
    }
    cout << "Longest path is: " << mx << endl;
}