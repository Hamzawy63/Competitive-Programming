#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const int maxN = 1e5 + 3;
vector<int> par(maxN);
 
int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}
 
void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}
 
struct Edge {
    ll u, v, cost;
 
    bool operator<(const Edge o) {
        return cost < o.cost;
    }
};
 
vector<Edge> g;
vector<pair<int, int>> g2[maxN];
vector<Edge> res;
 
void dfs(int cur, int par = -1) {
    for (auto adj : g2[cur]) {
        int to = adj.ff;
        if (to != par) {
            res.push_back({cur, to, adj.ss});
            dfs(to, cur);
        }
    }
}
 
void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<vector<vector<char>>> a(k, vector<vector<char>>(n, vector<char>(m)));
    for (int kk = 0; kk < k; kk++) {
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                a[kk][i][j] = s[j];
            }
        }
    }
    if (k == 1) {
        cout << n * m << endl;
        cout << 1 << space << 0 << endl;
        return;
    }
    for (int c1 = 0; c1 < k; c1++) {
        for (int c2 = c1 + 1; c2 < k; c2++) {
            ll cost = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cost += (a[c1][i][j] != a[c2][i][j]);
                }
            }
            cost *= w;
            g.push_back({c1, c2, min(cost, 1ll * n * m)});
            //g.push_back({min(cost, 1ll * n * m), {c1, c2}});
        }
    }
    sort(g.begin(), g.end());
    ll total = 0;
    for (int i = 0; i < k; i++) par[i] = i;
    for (int i = 0; i < (int) g.size(); i++) {
        int u = g[i].u;
        int v = g[i].v;
        int cost = g[i].cost;
        int uu = find(u);
        int vv = find(v);
        if (uu != vv) {
            merge(uu, vv);
            total += cost;
            g2[u].push_back({v, cost});
            g2[v].push_back({u, cost});
        }
    }
    cout << total + n * m << endl;
    dfs(0);
    for (int i = 0; i < (int) res.size(); i++) {
        int u = res[i].u;
        int v = res[i].v;
        int cost = res[i].cost;
        if (i == 0) {
            cout << u + 1 << space << 0 << endl;
        }
        cout << v + 1 << space << ((cost != n * m) ? u + 1 : 0) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
