#include<bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 20;

struct DSU {
    vector<int> s, p;
    DSU(int n) {
        s.resize(n);
        p.resize(n);
        for (int i = 0; i < n; i++) {
            s[i] = 1;
            p[i] = i;
        }
    }

    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (s[a] < s[b]) swap(a, b);

        p[b] = a;
        s[a] += s[b];
        return true;
    }
};

vector<vector<pair<int, int>>> g;
vector<int> w;
vector<bool> good;

vector<vector<int>> pr, mx;
vector<int> h;

void dfs(int v, int ww = 0, int p = -1) {
    pr[0][v] = p == -1 ? v : p;
    mx[0][v] = ww;
    h[v] = p == -1 ? 0 : h[p] + 1;
    for (int bit = 1; bit < MB; bit++) {
        pr[bit][v] = pr[bit - 1][pr[bit - 1][v]];
        mx[bit][v] = max(mx[bit - 1][v], mx[bit - 1][pr[bit - 1][v]]);
    }

    for (auto& pp : g[v]) {
        int u = pp.first;
        int id = pp.second;
        if (good[id] && u != p) {
            dfs(u, w[id], v);
        }
    }
}

int get(int a, int b) {
    int res = 0;
    if (h[a] < h[b]) swap(a, b);
    for (int bit = MB - 1; bit >= 0; bit--) {
        if (h[pr[bit][a]] >= h[b]) {
            res = max(res, mx[bit][a]);
            a = pr[bit][a];
        }
    }
    if (a == b) return res;
    for (int bit = MB - 1; bit >= 0; bit--) {
        if (pr[bit][a] != pr[bit][b]) {
            res = max(res, max(mx[bit][b], mx[bit][a]));
            a = pr[bit][a];
            b = pr[bit][b];
        }
    }
    return max(res, max(mx[0][a], mx[0][b]));
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    w.resize(m);
    vector<pair<pair<int, int>, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int from, to, ww;
        cin >> from >> to >> ww;
        from--; to--;
        w[i] = ww;
        g[from].push_back({ to, i });
        g[to].push_back({ from, i });
        edges[i] = { {ww, i}, {from, to} };
    }
    
    DSU dsu(n);
    good.resize(m);

    sort(edges.begin(), edges.end());

    int res = 0;
    for (int i = 0; i < m; i++) {
        int ww = edges[i].first.first;
        int id = edges[i].first.second;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (dsu.unite(a, b)) {
            res += ww;
            good[id] = true;
        }
    }

    h.resize(n);
    pr.resize(MB, vector<int>(n));
    mx.resize(MB, vector<int>(n, -INF));
    dfs(0);

    int ans = INF;
    for (int i = 0; i < m; i++) {
        int ww = edges[i].first.first;
        int id = edges[i].first.second;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(good[id] == 0){
            ans = min(ans, res - get(a, b) + ww);
        }
        int x = 0;
    }
    cout << ans << endl;
}