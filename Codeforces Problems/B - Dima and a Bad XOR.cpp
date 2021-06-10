#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
/*
 * dp[i][mask] -> dp[i+1][mask ^ a[j]] for all j in ith row
 */
int dp[501][1025];
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    int ans = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1024; j++) {
            if (dp[i][j]) {
                for (int k = 0; k < m; k++) {
                    dp[i + 1][j ^ a[i][k]] = k + 1;
                    if (i + 1 == n && ((j ^ a[i][k]) > 0)) {
                        ans = j ^ a[i][k];
                        idx = k + 1;
                        goto finish;
                    }
                }
            }
        }
    }
    finish:
    if (ans == 0)cout << "NIE" << endl;
    else {
        cout << "TAK" << endl;
        vector<int> res = {idx};
        for (int i = n - 1; i > 0; i--) {
            ans ^= a[i][idx - 1];
            idx = dp[i][ans];
            res.push_back(idx);
          // cerr << ans <<endl;
 
        }
        //cerr << ans <<endl;
        //res.push_back(idx);
        reverse(res.begin(), res.end());
        for (auto v : res) cout << v << " ";
        cout << endl;
    }
 
}
