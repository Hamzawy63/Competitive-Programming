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
const int maxN = 2001;
ll inf = 1e14;
ll dp[2002];
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < maxN; i++) {
        dp[i] = inf;
    }
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int t = a[i].ff + 1 ;
        ll c = a[i].ss;
        for (int j = n; j >= 0; j--) {
            dp[j] = min(dp[j], c + dp[max(j - t, 0)]);
        }
    }
    cout << dp[n] << endl;
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
