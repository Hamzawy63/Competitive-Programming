#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
 
 
const int Mod = (int) ((int) 1e9 + 7);
 
 
struct Circle {
    int c, r, idx;
 
    bool operator<( const Circle &o)  const {
        return c < o.c;
    }
 
};
 
bool valid(int x, int y, Circle circle) {
    int c_x = circle.c;
    ll dx = c_x - x;
    ll dy = y;
    return dx * dx + dy * dy <= circle.r * 1ll * circle.r;
}
 
void solve() {
    int n;
    cin >> n;
    vector<Circle> a;
    for (int i = 0; i < n; i++) {
        int c, r;
        cin >> c >> r;
        a.push_back({c, r, i});
//        a.emplace_back(c, r, i);
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    vector<int> res(n, -1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        auto it1 = lower_bound(a.begin(), a.end(), (Circle) {x, -1, -1});
        auto it2 = --it1;
        ++it1;
        if (it1 != a.end() && valid(x, y, *it1)) {
            int idx = (*it1).idx;
            if (res[idx] == -1) res[idx] = i;
        }
        if (it1 != a.begin() && valid(x, y, *it2)) {
            int idx = (*it2).idx;
            if (res[idx] == -1) res[idx] = i;
        }
    }
    int sz = n;
    for (auto v : res) {
        sz -= (v == -1);
    }
    cout << sz << endl;
    for (auto v : res) {
        if (v == -1) v -= 1;
        cout << v + 1 << space;
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
