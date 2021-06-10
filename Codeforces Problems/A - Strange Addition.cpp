#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
 
bool valid(int i, int j) {
    bool ok = true;
    while (i > 0 && j > 0) {
        int l1 = i % 10, l2 = j % 10;
        if (l1 != 0 && l2 != 0) return false;
        i /= 10;
        j /= 10;
    }
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> best;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> res = {a[i]};
        for (int j = 0; j < n; j++) {
            bool ok = true;
            if (i == j)continue;
            for (auto k : res) {
                if (!valid(k, a[j])) {
                    ok = false;
                }
            }
            if (ok) {
                res.push_back(a[j]);
            }
        }
        if ((int) res.size() > ans) {
            ans = (int) res.size();
            best.clear();
            for (auto v : res)best.push_back(v);
        }
    }
    cout << ans << endl;
    for (auto v : best) {
        cout << v << space;
    }
    cout << endl;
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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
