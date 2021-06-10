#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
using namespace std;
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define MOD (int)(1e9  + 7)
#define  ff first
#define  ss second
#define space " "
 
void build(vector<ll> &fen) {
    int n = (int) fen.size();
    for (int i = 0; i < n; i++) fen[i] = 0;
}
 
ll sum(vector<ll> &fen, int r) {
    int n = (int) fen.size();
    ll res = 0;
    for (; r >=0 ; r = (r & (r + 1)) - 1) res += fen[r];
    return res;
}
 
void update(vector<ll> &fen, int idx, ll delta) {
    int n = (int) fen.size();
    for (; idx < n; idx |= (idx + 1)) fen[idx] += delta;
}
 
void solve() {
    IO;
    int n;
    cin >> n;
    vector <pair<int, int >> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].ff;
    for (int i = 0; i < n; i++) cin >> p[i].ss;
    sort(p.begin(), p.end());
 
    vi vs;
    for (auto pnt : p) vs.push_back(pnt.second);
    sort(vs.begin(), vs.end());
    vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
 
    int diff = (int) vs.size();
    vector<ll> cnt(diff);
    vector<ll> xs(diff);
    build(cnt);
    build(xs);
    ll ans = 0;
    for (auto &pnt : p) {
        int pos = lower_bound(vs.begin(), vs.end(), pnt.second) - vs.begin();
        ll count = sum(cnt, pos);
        ll xSum = sum(xs, pos);
        ans += count * 1ll * pnt.first - xSum;
        update(cnt, pos, 1);
        update(xs, pos, pnt.first);
    }
    cout << ans << endl;
 
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    IO;
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        //cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();
 
    return 0;
}
