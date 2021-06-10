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
const int maxN = 1e3 + 3;
vector<int> par(maxN);
vector<int> vis(maxN);
vector<int> g[maxN];
 
int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}
 
void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}
 
 
void dfs(int cur) {
    vis[cur] = 1;
    for (auto to: g[cur]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> build;
    vector<pair<int, int>> remove;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (i != 0) {
                build.push_back(i);
                g[i].push_back(0);
                g[0].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) { par[i] = i; }
    set<pair<int, int>> st;
    for (int u = 0; u < n; u++) {
        for (auto v : g[u]) {
            if (st.count(make_pair(u, v)) || st.count(make_pair(v, u))) continue;
            st.insert(make_pair(u, v));
            int uu = find(u);
            int vv = find(v);
            if (uu == vv) {
                remove.push_back({u, v});
            } else {
                merge(uu, vv);
            }
        }
    }
    cout << build.size() << endl;
    for (int i = 0; i < (int) remove.size(); i++) {
        cout << remove[i].ff + 1 << space << remove[i].ss + 1 << space << build[i] + 1 << space << 1 << endl;
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
