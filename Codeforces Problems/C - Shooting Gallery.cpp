#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
 
struct Node {
    int x, y, t;
    double p;
 
    bool operator<(const Node &o) const {
        return t < o.t;
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        int x, y, t;
        double p;
        cin >> x >> y >> t >> p;
        a[i] = {x, y, t, p};
    }
    sort(a.begin(), a.end());
    vector<double> dp(n);
    double ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = a[i].p;
        for (int j = i + 1; j < n; j++) {
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            int dt = a[i].t - a[j].t;
            if (dx * dx + dy * dy <= dt * 1LL * dt)
                dp[i] = max(dp[i], a[i].p + dp[j]);
//                dp[i] = max(dp[i], a[i].p + (1 - a[i].p) * dp[j]);
        }
        ans = max(dp[i], ans);
    }
 
    cout << setprecision(7) << fixed << ans << endl;
 
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        //  cout << "Case #" << i << ": ";
        solve();
    }
}
