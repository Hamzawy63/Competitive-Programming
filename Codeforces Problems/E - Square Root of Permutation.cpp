#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int maxN = 1000000 + 4;
vector<int> g(maxN);
vector<bool> vis(maxN);
int n;
vector<int> cycle;
vector<int> res(maxN);
vector<int> even_cycles[maxN];
 
void dfs(int cur) {
    cycle.pb(cur);
    vis[cur] = 1;
    int to = g[cur];
    if (!vis[to]) {
        dfs(to);
    } else {
//        for (auto v : cycle) {
//            cerr << v << space;
//        }
//        cerr << endl;
        int sz = (int) cycle.size();
        if (sz % 2 == 1) {
            for (int i = 0, j = ((sz / 2) + 1)%sz; i < sz; i++, j = (j + 1) % sz) {
                int parent = cycle[i];
//                int child = cycle[(i + (sz / 2)) % sz];
                int child = cycle[j];
                res[parent] = child;
            }
        } else {
            if (even_cycles[sz].empty()) {
                even_cycles[sz] = cycle;
            } else {
                for (int i = 0; i < sz; i++) {
                    res[even_cycles[sz][i]] = cycle[i];
                    res[cycle[i]] = even_cycles[sz][(i + 1) % sz];
                }
                even_cycles[sz].clear();
            }
        }
        cycle.clear();
    }
 
}
 
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        g[i] = t;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    for (int i = 0; i < maxN; i++) {
        if (!even_cycles[i].empty()) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << space;
    }
    cout << endl;
 
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
