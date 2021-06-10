#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
int main() {
    int n;
    cin >> n;
    const int inf = 2e9;
    vector<int> dp(1 << 3, inf);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        int cost;
        string s;
        cin >> cost >> s;
        int mask = 0;
        for (auto c : s) {
            mask |= (1 << (c - 'A'));
        }
        dp[0] = 0 ;
        for (int j = 0; j <= 7; j++) {
            for (int k = 0; k < j; k++) {
                if ((mask | k) == j) {
                    dp[j] = min(dp[j], cost + dp[k]);
                }
            }
        }
    }
    if (dp[7] == inf) {
        cout << -1 << endl;
    } else
        cout << dp[7] << endl;
}
