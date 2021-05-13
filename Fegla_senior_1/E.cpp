#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, U;
    cin >> n >> U;
    vector<long long int > a(n + 3, 0);
    while (U--) {
        int L, R, d ;
        cin >> L >> R >> d ;
        a[L] += d;
        a[R + 1] -= d;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
//        cerr << a[i] << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        int idx;
        cin >> idx;
        cout << a[idx] << endl;
    }
}

int main() {
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}