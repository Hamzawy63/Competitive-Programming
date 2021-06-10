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
 
ll bound(ll nl, ll nr) {
    ll ans = min(9LL, nr);
    for (ll d = 2; d <= 18; d++) {
//        cerr << ans << endl;
        ll lb = 0, rb = (ll) pow(10, d - 2) - 1;
        for (ll i = 1; i < 10; i++) {
            ll L = lb, R = rb;
            ll bans = 0;
            string debug = "";
            while (L <= R) {
                ll mid = (L + R) / 2;
                ll cur = mid * 10 + i + i * (ll) pow(10, d - 1);
                if (cur >= nl && cur <= nr) {
                    debug = "when d = " + to_string(d) + " and cur = " + to_string(cur) + " and bans = ";
                    bans = mid + 1;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            if (!debug.empty())
              //  cerr << debug << bans << endl;
            ans += bans;
        }
    }
   // cerr << ans << endl;
    return ans;
}
 
void solve() {
    ll l, r;
    cin >> l >> r;
    ll res = 0;
    res = bound(1, r) - bound(1, l - 1);
    cout << res << endl;
 
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
