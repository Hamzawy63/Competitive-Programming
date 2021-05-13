#include <bits/stdc++.h>

using namespace std;
bool debug = false;

int main() {
#ifdef  _SHIT
    debug = true;
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s, l;
    cin >> n >> s >> l;
    vector<int> a(n);
    int b = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b = min(b, a[i]);
    }
    vector<vector<int>> tbmin(n, vector<int>(20, 0));
    vector<vector<int>> tbmax(n, vector<int>(20, 0));
    for (int k = 0; k <= 20; k++) {
        for (int i = 0; (i + (1 << k)) - 1 < n; i++) {
            if (k == 0) {
                tbmin[i][k] = a[i];
                tbmax[i][k] = a[i];
                continue;
            }
            tbmin[i][k] = min(tbmin[i][k - 1], tbmin[i + (1 << (k - 1))][k - 1]);
            tbmax[i][k] = max(tbmax[i][k - 1], tbmax[i + (1 << (k - 1))][k - 1]);
        }
    }
    auto get_min = [&](int L, int R) {
        int ln = (R - L + 1);
        int lg = (int) log2(R - L + 1);
        int ans = min(tbmin[L][lg], tbmin[R + 1 - (1 << lg)][lg]);
        if (debug) {
            fprintf(stderr, "get_min(%d,%d) = min(tbmin[%d][%d], tbmin[%d][%d] = min(%d, %d) = %d \n", L, R, L, lg,
                    R + 1 - (1 << lg), lg, tbmin[L][lg], tbmin[R + 1 - (1 << lg)][lg], ans);
        }
        return ans;
    };
    auto get_max = [&](int L, int R) {
        int ln = (R - L + 1);
        int lg = (int) log2(R - L + 1);
        int ans = max(tbmax[L][lg], tbmax[R + 1 - (1 << lg)][lg]);
        if (debug)
            fprintf(stderr, "get_max(%d,%d) = max(tbmax[%d][%d], tbmax[%d][%d] = max(%d, %d) = %d \n", L, R, L, lg,
                    R + 1 - (1 << lg), lg, tbmax[L][lg], tbmax[R + 1 - (1 << lg)][lg], ans);
        return ans;
    };
    vector<int> dp(n + 1);
    dp[0] = 1;
    int L = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (i - L + 1 < l) {
            dp[i] = -1;
            continue;
        } else {
            int mx = get_max(L, i);
            int mn = get_min(L, i);
            while ((mx - mn > s) || (L && (dp[L - 1] == -1))) {
                if (L >= i) {
                    break;
                }
                L += 1;
                mx = get_max(L, i);
                mn = get_min(L, i);
            }
            if (i - L + 1 < l || mx - mn > s)
                dp[i] = -1;
            else {
                dp[i] = 1;
                if (L)dp[i] += dp[L - 1];
            }
            fprintf(stderr, "%d %d\n", i, dp[i]);
        }

    }
    cout << dp[n - 1] << '\n';


    return 0;
}