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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = a[i];
        if (i) p[i] += p[i - 1];
    }
    vector<ll> dp(n, -1), st(n); // good ending in R
    for (int i = k - 1; i < n; i++) {
        ll best_ending_here = p[i] - ((i - k > -1) ? p[i - k] : 0);
        if (i == 0) {
            dp[i] = best_ending_here;
            st[i] = i - k + 1;
            continue;
        }
        dp[i] = dp[i - 1];
        st[i] = st[i - 1];
        if (best_ending_here > dp[i - 1]) {
            dp[i] = best_ending_here;
            st[i] = i - k + 1;
        }
    }
//    for (int i = 0; i < n; i++) {
////        cerr << dp[i] << space;
////    }
////    cerr << endl;
////
////    for (int i = 0; i < n; i++) {
////        cerr << st[i] << space;
////    }
////    cerr << endl;
    ll res = -1;
    pair<int, int> ans;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] != -1 && i + k - 1 < n) {
            ll soln = dp[i - 1] + (p[i + k - 1] - p[i - 1]);
            if (soln > res) {
                res = soln;
                ans = {st[i - 1], i};
            }
        }
    }
   // cout << res << endl;
    cout << ans.ff + 1 << space << ans.ss + 1 << endl;
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
