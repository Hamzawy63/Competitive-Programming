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

//#define _DEBUG
void solve() {
    int n, q;
    cin >> n >> q;
    vii dp(n + 1, vi(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        string s ;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (s[j-1] == '*');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1] << endl;
    }
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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}