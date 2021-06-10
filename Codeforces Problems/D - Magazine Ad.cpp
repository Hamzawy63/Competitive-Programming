#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<char>> dp(1004, vector<char>(2100, '?'));
    auto valid = [&](int i, int j) {
        if (i == n) return true;
        if (abs(k - j) == k) return false;
        else return true;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2 * k; j++) {
            if ((i == 0 && j == k) || dp[i][j] != '?') {
                if (s[i] == 'L') {
                    if (j - 1 >= 0) {
                        if (valid(i + 1, j - 1))
                            dp[i + 1][j - 1] = 'L';
                    }
                } else if (s[i] == 'D') {
                    if (valid(i + 1, j))dp[i + 1][j] = 'D';
                } else if (s[i] == 'W') {
                    if (valid(i + 1, j + 1)) dp[i + 1][j + 1] = 'W';
                } else {
                    if (j - 1 >= 0) {
                        if (valid(i + 1, j - 1)) dp[i + 1][j - 1] = 'L';
                    }
                    if (valid(i + 1, j))dp[i + 1][j] = 'D';
                    if (valid(i + 1, j + 1))dp[i + 1][j + 1] = 'W';
                }
            }
        }
    }
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= 2 * k; j++) {
//            cerr << dp[i][j] << " ";
//        }
//        cerr << endl;
//    }
    if (dp[n][2 * k] != '?') {
        string res = "";
        int j = 2 * k;
        for (int i = n; i > 0; i--) {
            res += dp[i][j];
            if (dp[i][j] == 'L') {
                j += 1;
            } else if (dp[i][j] == 'W') {
                j -= 1;
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    } else if (dp[n][0] != '?') {
        string res = "";
        int j = 0;
        for (int i = n; i > 0; i--) {
            res += dp[i][j];
            if (dp[i][j] == 'L') {
                j += 1;
            } else if (dp[i][j] == 'W') {
                j -= 1;
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
 
    } else {
        cout << "NO" << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO5
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
