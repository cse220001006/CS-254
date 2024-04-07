#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+10;

int par[N];
int siz[N];

void make(int v){
    par[v] = v;
    siz[v] = 1;
}

int find(int v){
    if(par[v] == v) return v;
    return par[v] = find(par[v]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a] < siz[b]) swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
    }
}

int main(){
    int n, edges; cin >> n >> edges;
    priority_queue<pair<int, pair<int, int>>> q;
    for(int i = 0; i <= n; i++){
        make(i);
    }
    while(edges--){
        int x, y, w; cin >> x >> y >> w;
        q.push({w, {x, y}});
    }
    int ct = 0;
    int ans = 0;
    cout << "Maximum Spanning tree is: " << endl;
    while(q.size() > 0){
        auto p = q.top();
        q.pop();
        int w = p.first, u = p.second.first, v = p.second.second;
        if(find(u) != find(v)){
            cout << u << " " << v << endl;
            ans += w;
            uni(u, v);
            ct++;
        }
        if(ct == n){
            break;
        }
    }
}
