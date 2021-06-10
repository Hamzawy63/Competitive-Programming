#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
const int maxN = 2000;
const int N = maxN + 4;
int dp[N][N];
 
void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= maxN; i++) {
        for (int j = 0; j <= maxN; j++) {
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < h; j++) {
            int t1 = (j - (a[i-1] -1) + h) % h;
            int t2 = (j - a[i-1]  + h) % h;
            if (dp[i - 1][t1] != -1) {
                dp[i][j] = max(dp[i][j], (j >= l && j <= r) + dp[i - 1][t1]);
            }
            if (dp[i - 1][t2] != -1) {
                dp[i][j] = max(dp[i][j], (j >= l && j <= r) + dp[i - 1][t2]);
            }
            ans = max(dp[i][j], ans);
        }
 
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < h; j++) cerr << (dp[i][j] == -1 ? "*" : to_string(dp[i][j]) )<< space;
//        cerr << endl;
//    }
    cout << ans << endl;
 
}
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    //  cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
