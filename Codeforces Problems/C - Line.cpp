#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)
#define  ff first
#define  ss second
 
pair<ll, ll> bezout(ll a, ll b) {
    if (b == 0) return {1, 0};
    pair<ll, ll> nxt = bezout(b, a % b);
    return {nxt.ss, nxt.ff - (a / b) * nxt.ss};
}
 
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = __gcd(a, b);
    if (c % g != 0) {
        cout << -1 << endl;
        return;
    } else {
        pair<ll, ll> coeff = bezout(a, b);
        ll s = coeff.ff;
        ll t = coeff.ss;
        cout << s * -1 * (c / g) << space << t * -1 * (c / g) << endl;
    }
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    IO;
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();
 
    return 0;
}
