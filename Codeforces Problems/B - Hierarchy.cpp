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
 
void solve() {
    int n;
    cin >> n;
    vector<int> q(n);
    vector<int> root;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    //   sort(q.begin(), q.end());
//    if (q[n - 1] == q[n - 2]) {
//        cout << -1 << endl;
//        return;
//    }
    int m;
    cin >> m;
    vector<int> par(n, -1);
    ll ans = 0;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        if (par[v] == -1) {
            par[v] = c;
            ans += c;
        } else {
            ans -= par[v];
            par[v] = min(par[v], c);
            ans += par[v];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1) cnt++;
    }
    if (cnt != 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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
