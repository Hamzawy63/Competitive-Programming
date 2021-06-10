#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {-2, -2, 2, 2, 1, -1, 1, -1};
const vector<int> dy = {1, -1, 1, -1, -2, -2, 2, 2};
const int maxN = 100000;
int c[maxN + 1];
vector<int> g[maxN + 1];
int n;
void dfs(int cur, int par = -1) {
    for (auto to : g[cur]) {
        if (to != par) {
            if (c[to] == -1) {
                c[to] = c[cur] ^ 1;
                dfs(to ,cur ) ;
            }
        }
    }
}
 
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        c[i] = -1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    c[0] = 0;
    dfs(0);
    int o = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) o++;
        else z++;
    }
    cout << o * 1ll * z - (n - 1) << endl;
}
 
int main() {
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
