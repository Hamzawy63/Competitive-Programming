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
#define INF  (int)1000000000
int dp[(int) 1e5 + 3][103];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    const int Mod = (int) 1e9 + 7;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 0) {
                dp[i][j] = (!a[i]) || (a[i] == j);
            } else {
                if (!a[i] || a[i] == j)
                    dp[i][j] = (((ll) dp[i - 1][j + 1] + dp[i - 1][j] + dp[i - 1][j - 1])) % Mod;
            }
            if (i == n - 1) {
                ans = ans + dp[i][j];
                ans %= Mod;
            }
        }
    }
    cout << ans << endl;

    return 0;
}