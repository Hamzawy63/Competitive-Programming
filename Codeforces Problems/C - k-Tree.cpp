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
int dp[102][102]; // weight = i with max leaf = j
const int Mod = (int) 1e9 + 7;
 
int add(int a, int b) {
    return (a + b) % Mod;
}
 
void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                if (i + l <= n) {
                    dp[i + l][max(j, l)] = add(dp[i + l][max(j, l)], dp[i][j] );
                }
            }
 
        }
    }
    int ans = 0;
    for (int j = d; j <= k; j++) {
        ans = add(ans, dp[n][j]);
    }
    cout << ans <<endl;
 
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
