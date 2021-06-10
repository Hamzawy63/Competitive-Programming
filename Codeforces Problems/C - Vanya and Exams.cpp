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
 
void check(bool ok) {
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
const ll MAX = (ll) 1e18;
int maxN = 1e6;
 
void solve() {
    int n, r, avg;
    cin >> n >> r >> avg;
    vector<pair<int, int>> a(n);
    ll sa = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ss >> a[i].ff;
        sa += a[i].ss;
    }
    sort(a.begin(), a.end());
    ll need = avg * 1LL * n - sa;
    ll cost = 0;
    for (int i = 0; need > 0 && i < n; i++) {
        int aa = a[i].ss;
        int bb = a[i].ff;
        int take = min(need, (ll) r - aa);
        need -= take;
        cost += take * 1ll * bb;
    }
    cout << cost << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
    //  freopen("output.txt", "w", stdout);
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
