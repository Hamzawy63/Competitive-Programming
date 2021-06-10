#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
bool dp[20][700];
 
int main() {
    // dp[i][angle  =j ] = dp[i-1][j-a[i]] || dp[i-1][j + a[i]]
    int n;
    cin >> n;
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < 360; j++) {
            int p = (j - t + 360) % 360;
            int f = (j + t) % 360;
            dp[i + 1][j] = dp[i][p] || dp[i][f];
        }
    }
    if (dp[n][0]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
