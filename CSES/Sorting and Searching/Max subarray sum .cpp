#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = INT_MIN, res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    for (int i = 0; i < n; i++) {
        res += a[i];
        ans = max(res, ans);
        res = max(0LL, res);
    }
    cout << ans << endl;

}