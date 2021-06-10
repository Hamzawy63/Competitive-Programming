#include <bits/stdc++.h>
 
using namespace std;
typedef unsigned long long int ll;
typedef long double ld;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    ld check = (k *(ld) (k + 1))/2;
    if (check > n) {
        cout << -1 << endl;
        return;
    }
    ll need = (k * (k + 1)) / 2;
    auto can = [&](ll div) {
        ll sum = n / div;
        return sum >= need;
    };
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++) {
        if ((n / i) * i == n) {
            if (can(i)) ans = max(ans, i);
            if (can(n / i)) ans = max(ans, n / i);
        }
    }
    if (ans == -1) {
        cout << -1 << '\n';
    } else {
        ll carry = (n / ans) - need;
        for (ll i = 1; i <= k; i++) {
            ll num = i;
            if (i == k) num += carry;
            cout << ans * num << ' ';
        }
        cout << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO5
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
