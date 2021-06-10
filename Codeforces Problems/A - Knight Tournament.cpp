#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const int maxN = 3e5 + 3;
vector<int> seg(4 * maxN, -1);
int lazy[4 * maxN];
int ans[maxN];
int n;
 
void push(int v, int len) {
    if (lazy[v]) {
        if (len > 1) {
            seg[2 * v] = seg[v];
            seg[2 * v + 1] = seg[v];
            lazy[2 * v + 1] = 1;
            lazy[2 * v] = 1;
        }
        lazy[v] = 0;
    }
}
 
void update(int L, int R, int val, int tl = 0, int tr = n - 1, int v = 1) {
    if (L > R) return;
    if (tl == L && tr == R) {
        seg[v] = val;
        lazy[v] = true;
        return;
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update(L, min(tm, R), val, tl, tm, 2 * v);
    update(max(tm + 1, L), R, val, tm + 1, tr, 2 * v + 1);
}
 
void get(int tl = 0, int tr = n - 1, int v = 1) {
    push(v, tr - tl + 1);
    if (tl == tr) {
        ans[tl] = seg[v];
        return;
    }
    int tm = (tl + tr) / 2;
    get(tl, tm, 2 * v);
    get(tm + 1, tr, 2 * v + 1);
}
 
void solve() {
    int q;
    cin >> n;
    cin >> q;
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < q; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        l--;
        r--;
        w--;
        a.push_back(make_tuple(l, r, w));
    }
    reverse(a.begin(), a.end());
    for (auto t : a) {
        int l = get<0>(t);
        int r = get<1>(t);
        int w = get<2>(t);
        update(l, w - 1, w);
        update(w + 1, r, w);
    }
    get();
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << space;
    }
    cout << endl;
 
 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
