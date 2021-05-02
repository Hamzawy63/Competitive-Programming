#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
const int maxN = 5e3 + 3;
int dp[maxN][maxN];
const int inf = 1e9;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = max(i, j);
            } else {
                char ss = s[i - 1];
                char tt = t[j - 1];
                if (ss == tt)
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1] , dp[i-1][j]);

                }
            }

        }
    }
    cout << dp[n][m] << endl;
    return 0;
}