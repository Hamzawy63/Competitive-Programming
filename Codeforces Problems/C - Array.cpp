#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
typedef long long int ll;
using namespace std;
const int Mod = 1000000007;
 
ll powmod(ll a, ll b) {
    int mod = 1000000007;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}
 
ll inv(int n) {
    return powmod(n, Mod - 2);
 
}
 
void solve() {
    int n;
    cin >> n ;
    vector<int> fac(2 * n);
    fac[0] = 1;
    for (int i = 1; i < 2 * n; i++) fac[i] = (fac[i - 1] * 1ll * i) % Mod;
    ll res = fac[2 * n - 1];
    res = (res * inv(fac[n])) % Mod;
    res = (res * inv(fac[n - 1])) % Mod;
    cout << (res * 2)% Mod  - n   << endl;
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//    }
 
    solve();
 
    return 0;
}
