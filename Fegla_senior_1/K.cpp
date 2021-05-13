#include <bits/stdc++.h>
// https://codeforces.com/problemset/problem/1207/F
using namespace std;

const int N = 500000;
long long int dp[803][802];
long long int a[N + 1];

int main() {
    #ifdef  _SHIT
        freopen("../in" , "r" , stdin) ;
        freopen("../out" , "w" , stdout) ;
    #endif
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    int sq = 800;
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] += y;
            for (int i = 1; i <= 800; i++) {
                dp[i][x % i] += y;
            }
        } else {
            if (x >= sq) {
                long long int ans = 0;
                for (int i = y; i <= N; i += x) {
                    ans += a[i];
                }
                cout << ans << '\n';
            } else {
                if (dp[x][y] == -1) {
                    int ans = 0;
                    for (int i = y; i <= N; i += x) {
                        ans += a[i];
                    }
                    cout << ans << '\n';
                    dp[x][y] = ans ;
                }else {
                    cout << dp[x][y] << '\n';
                }
            }
        }
    }
    return 0;
}