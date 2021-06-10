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
const int maxN = 100000 + 2;
vector<int> g[maxN];
vector<int> a(maxN);
vector<int> c(maxN);
vector<int> vis(maxN);
vector<int> res;
 
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = 0;
        vis[i] = 0;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (c[i] == a[i]) {
            vis[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (c[cur] == a[cur]) {
            c[cur]++;
            res.push_back(cur + 1);
            for (auto to : g[cur]) {
                c[to]++;
                if (!vis[to]) {
                    q.push(to);
                }
            }
        }
    }
    cout << (int) res.size() << endl;
    for (auto v : res) {
        cout << v << space ;
    }
    cout << endl;
 
 
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
