#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
const ll inf = 1e18;
const int maxN = 202;
int k, n;
string s, t;
int dp[maxN][maxN][maxN];
int main() {
    cin >> n >> k;
    cin >> s >> t;
    if (t[0] == t[1]) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[0]) ans++;
            else if (s[i] != t[0] && k) {
                ans++;
                k--;
            }
        }
        cout << ans * (ans - 1) / 2 << endl;
        return 0;
    }
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int kk = 0; kk <= 200; kk++) {
                dp[i][j][kk] = -1;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int pre = 0; pre <= i; pre++) {
            for (int kk = 0; kk <= k; kk++) {
                if (dp[i][pre][kk] == -1 ) continue;
                if(pre > i ) cerr << "Damn it " <<endl;
                if (s[i] == t[0]) {
                    dp[i + 1][pre + 1][kk] = max(dp[i + 1][pre + 1][kk], dp[i][pre][kk]);
                    dp[i + 1][pre][kk + 1] = max(dp[i + 1][pre][kk + 1], dp[i][pre][kk] + pre); // change to second L)
                } else if (s[i] == t[1]) {
                    dp[i + 1][pre][kk] = max(dp[i + 1][pre][kk], dp[i][pre][kk] + pre);
                    dp[i + 1][pre + 1][kk + 1] = max(dp[i + 1][pre + 1][kk + 1], dp[i][pre][kk]);
                } else {
                    dp[i + 1][pre][kk] = max(dp[i + 1][pre][kk], dp[i][pre][kk]); // no change at all
                    dp[i + 1][pre + 1][kk + 1] = max(dp[i + 1][pre + 1][kk+1], dp[i][pre][kk]); // change the first
                    dp[i + 1][pre][kk + 1] = max(dp[i + 1][pre][kk + 1], pre + dp[i][pre][kk]);
                }
//                cerr << i << " " << pre << " " << kk  << " " << ans <<endl;
            }
        }
    }
    int ans = 0;
    for (int pre = 0; pre <= n; pre++) {
        for (int kk = 0; kk <= k; kk++) {
            ans = max(ans, dp[n][pre][kk]);
        }
    }
    cout << ans <<endl ;
 
}
