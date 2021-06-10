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
 
#define _DEBUG
const int maxN = 2001;
ll inf = 1e14;
ll dp[102][10002];
 
void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = -1;
        }
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i] = c[i] * (n - i);
    }
    dp[0][0] = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (dp[i][j] != -1) {
                if (j + c[i] <= x)
                    dp[i + 1][j + c[i]] = max(dp[i + 1][j + c[i]], 1 + dp[i][j]);
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            }
        }
 
    }
    for (int i = 0; i <= x; i++) {
        ans = max(ans * 1LL, dp[n][i]);
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
