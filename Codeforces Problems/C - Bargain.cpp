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
#define mp make_pair
//vi dx = {-1, 0, 0, 1};
//vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
 
int powmod(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * 1LL * a) % Mod;
        }
        b >>= 1;
        a = (a * 1LL * a) % Mod;
    }
    return ans;
}
 
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vi ten(n + 1), dp(n), prefix(n), before(n), after(n);
    ten[0]  = 1  ;
    for (int i = 1; i <= n; i++) {
        ten[i] = (ten[i - 1] * 1LL * 10) % Mod;
    }
    before[0] = (s[0] - '0');
    prefix[0] = before[0];
    for (int i = 1; i < n; i++) {
        before[i] = (before[i - 1] * 1LL * 10) % Mod + (s[i] - '0');
        before[i] %= Mod;
        prefix[i] = ((ll) (before[i] + prefix[i - 1])) % Mod;
    }
    after[n - 1] = (s[n - 1] - '0');
    for (int i = n - 2; i >= 0; i--) {
        after[i] = ((s[i] - '0') * 1LL * ten[n - i -1  ]) % Mod;
        after[i] = ((ll) (after[i + 1] + after[i])) % Mod;
    }
    ll ans = after[1];
    for (int i = 1; i < n; ++i) {
        int m = (int) (n - i - 1);
        ll res = (ten[m] * 1LL * prefix[i - 1]) % Mod;
        if (i + 1 < n)
            res += ((after[i + 1] * 1LL * (i + 1)) % Mod);
        res %= Mod;
        ans = (ans + res) % Mod;
    }
    cout << ans << endl;
 
 
}
 
int main() {
#ifdef _DEBUG
    freopen("hello.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
