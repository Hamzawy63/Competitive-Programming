#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
//#define _DEBUG
const int maxN = 2e5 + 4;
ll inf = 1e14;
 
void solve() {
    int n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.back() == 'f') a[i] = 0;
        else a[i] = 1;
    }
    ll cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur = 2 * cur + a[i];
    }
    ll ans = 0;
    while (cur > 0) {
        if (cur / 2 > 0)
            ans += (cur / 2) * p;
        if (cur % 2) ans += p / 2;
        cur /= 2;
    }
    cout << ans << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
 
}
