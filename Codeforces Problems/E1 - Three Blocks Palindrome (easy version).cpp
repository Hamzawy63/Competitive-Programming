#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        vi cnt(30);
        vi dp(n);
        int all[n][30];
 
        for (int i = 0; i <= 26; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            a[i] = t ;
            cnt[t]++;
            dp[i] = cnt[t];
            for (int j = 1; j <= 26; j++) {
                all[i][j] = cnt[j];
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j] && (dp[i] == (cnt[a[i]] - dp[j] + 1)) ) {
                    int res = dp[i] + cnt[a[j]] - dp[j] + 1;
                    if (j > i + 1) {
                        int mid = 0;
                        for (int k = 1; k <= 26; k++) {
                            mid = max(mid, all[j - 1 ][k] - all[i][k]);
                        }
                        res += mid;
                    }
                    ans = max(ans, res);
                }
            }
        }
        cout << ans << endl;
 
    }
    return 0;
 
}
