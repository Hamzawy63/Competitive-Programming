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
 
void solve() {
    ll x1, x2, y1, y2, z1, z2;
    //     0     1      2
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    ll ans = 0;
    int x = min(z1 , y2 ) ; 
    ans = x * 2LL;
    y2 -= x;
    z1 -= x;
    ans -= 2LL * max(0LL, z2 - x1 - z1);
    cout << ans << endl;
 
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
