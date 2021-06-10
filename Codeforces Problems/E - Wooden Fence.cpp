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
const int maxN = 1e5 + 3;
const int inf = 1e7;
const int Mod = 1e9 + 7;
int dp[3002][102][2];
vector<pair<int, int>> a(102);
int n, L;
 
int solve(int cur_len, int last, int flip) {
    if (cur_len == L) {
        return 1;
    } else if (cur_len > L) {
        return 0;
    }
    if (last != -1 && dp[cur_len][last][flip] != -1)
        return dp[cur_len][last][flip];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == last)
            continue;
        int aa = a[i].ff;
        int bb = a[i].ss;
        if (last == -1) {
            ans += solve(cur_len + aa, i, 0);
            ans %= Mod;
            if (aa != bb) {
                ans += solve(cur_len + bb, i, 1);
                ans %= Mod;
            }
        } else {
            int last_w = flip ? a[last].ff : a[last].ss;
            if (aa == last_w) {
                ans += solve(cur_len + aa, i, 0);
                ans %= Mod;
            } else if (bb == last_w) {
                ans += solve(cur_len + bb, i, 1);
                ans %= Mod;
            }
        }
    }
    //  printf("dp[%d][%d][%d] = %d\n", cur_len, last, flip, ans);
    if (last != -1) {
        dp[cur_len][last][flip] = ans;
    }
    return ans;
}
 
void solve() {
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
 
    }
    cout << solve(0, -1, 0) << endl;
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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
 
}
