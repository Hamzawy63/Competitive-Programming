#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
void solve() {
    int n;
    cin >> n;
    int inf = 1e6;
    vector<int> a(n), dp(n, inf);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            last = i;
        }
        if (last != -1) {
            dp[i] = min(dp[i], i - last);
        }
    }
    last = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            last = i;
        }
        if (last != -1) {
            dp[i] = min(dp[i], last - i);
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[i] << " " ;
    }
    cout << endl;
 
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
