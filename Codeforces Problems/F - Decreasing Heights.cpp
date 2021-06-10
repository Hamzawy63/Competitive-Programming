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
#include <stack>
#include <memory.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
const ll INF = LONG_LONG_MAX;
 
void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n + 3][m + 3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = INF;
    ll dp[n + 3][m + 3];
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < m; jj++) {
            ll start = a[ii][jj] - ii - jj;
            if (a[0][0] < start) continue;
            else dp[0][0] = a[0][0] - start;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 && j == 0) continue;
                    ll should = start + (i + j);
                    if (a[i][j] < should) {
                        dp[i][j] = INF;
                        continue;
                    }
                    ll cost = a[i][j] - should;
                    dp[i][j] = INF;
                    if (i > 0) {
                        if (dp[i - 1][j] != INF)
                            dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost);
                    }
                    if (j > 0) {
                        if (dp[i][j - 1] != INF)
                            dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost);
                    }
                }
            }
            ans = min(ans, dp[n - 1][m - 1]);
 
//            cerr << "i = " << ii << "j = " << jj << endl;
//            for(int i=0;i<n;i++){
//                for(int j=0;j<m;j++){
//                    cerr << dp[i][j] << space ;
//                }
//                cerr << endl;
//            }
 
        }
    }
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
