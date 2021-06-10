#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
bool can(int mx, vector<int> &a, int k) {
    int n = (int) a.size();
    vector<ll> dp(n, 0);
    vector<ll> pre(n, 0);
    int st = 0;
    if (a[k - 1] - a[0] <= mx) {
        dp[k - 1] = 1;
        pre[k - 1] = 1;
    }
    for (int i = k; i < n; i++) {
        int end = i - (k - 1);
        while ((a[i] - a[st] > mx) && st <= i) {
            st += 1;
        }
        if (st > end) {
            dp[i] = 0;
        } else {
            int prefix = 0;
            int L = st - 1;
            int R = end - 1;
            if (L == -1) {
                dp[i] = 1;
            } else {
                prefix = pre[R];
                if (L) prefix -= pre[L - 1];
                if (prefix > 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = 0;
                }
            }
        }
        pre[i] = dp[i];
        if (i) pre[i] += pre[i - 1];
    }
#ifdef _SHIT
    for (int i = 0; i < n; i++) {
        cout << dp[i] << ' ';
    }
    cout << mx << endl;
#endif
    return dp[n - 1] == 1;
}
 
int main() {
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k == 1) {
        cout << 0 << '\n';
        return 0;
    }
    sort(a.begin(), a.end());
 
 
    int ans = 0;
    int lb = 0, rb = 1e9;
    while (lb <= rb) {
        int mb = lb + (rb - lb) / 2;
        if (can(mb, a, k)) {
            ans = mb;
            rb = mb - 1;
        } else {
            lb = mb + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
