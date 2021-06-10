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
 
const int maxN = 102;
vector<int> vis(maxN);
vector<int> g[maxN];
int kk = 0;
 
void dfs(int cur) {
    vis[cur] = 1;
    kk++;
    for (int to : g[cur]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    if (kk == n && (n == m)) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }
 
 
}
 
int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
