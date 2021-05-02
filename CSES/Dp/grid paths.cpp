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


const int maxN = 1003;
vector<string> grid(maxN);
int dp[maxN][maxN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid[i] = s;
    }
    const int Mod = 1e9 + 7;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - 1 > -1 && grid[i - 1][j] != '*') dp[i][j] += dp[i - 1][j];
            if (j - 1 > -1 && grid[i][j - 1] != '*') dp[i][j] += dp[i][j - 1];
            if (grid[i][j] == '*') dp[i][j] = 0;
            dp[i][j] %= Mod;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}