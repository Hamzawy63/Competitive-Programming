#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int maxN = 200 + 3;
vl r(maxN), g(maxN), b(maxN);
int R, G, B;
ll dp[maxN][maxN][maxN];
 
void solve() {
    cin >> R >> G >> B;
    for (int i = 0; i < R; i++) cin >> r[i];
    for (int i = 0; i < G; i++) cin >> g[i];
    for (int i = 0; i < B; i++) cin >> b[i];
    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(b.rbegin(), b.rend());
    ll ans = 0;
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            for (int k = 0; k < 201; k++) {
                //cerr << dp[i][j][k] << endl;
                dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
                dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
                dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans  << endl;
 
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
        solve();
    }
}
