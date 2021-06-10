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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    vector<int> f(n + 2);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        f[l] += 1;
        f[r + 1] -= 1;
    }
    for (int i = 1; i < n; i++) {
        f[i] += f[i - 1];
    }
    sort(f.begin(), f.end(), greater<int>());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f[i] * 1LL * a[i];
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
