#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
//#define _DEBUG
const int maxN = 2 * 100 * 1000 + 1;
vector<int> seg(4 * maxN);
void combine(int v) {
    seg[v] = min(seg[2 * v], seg[2 * v + 1]);
}
void build(int tl, int tr, int v, vi &a) {
    if (tl == tr) {
        seg[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, 2 * v, a);
        build(tm + 1, tr, 2 * v + 1, a);
        combine(v) ;
    }
}
void update(int tl, int tr, int v, int idx, int val) {
    if (tl == tr) {
        seg[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (tm >= idx) update(tl, tm, 2 * v, idx, val);
        else update(tm + 1, tr, 2 * v + 1, idx, val);
        combine(v);
    }
}
int get_minimum(int tl, int tr, int v, int l, int r) {
    if (l > r) return INT_MAX;
    if (tl == l && tr == r) return seg[v];
    int tm = (tl + tr) / 2;
    int f = get_minimum(tl, tm, 2 * v, l, min(tm, r));
    int s = get_minimum(tm + 1, tr, 2 * v + 1, max(tm+1, l), r);
    return min(f, s);
}
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1, 1, a);
    for (int i = 0; i < q; i++) {
        int f, s, t;
        cin >> f >> s >> t;
        if (f == 1) {
            s--;
            update(0, n - 1, 1, s, t);
        } else {
            s--;
            t--;
            cout << get_minimum(0, n - 1, 1, s, t) << endl;
        }

    }


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
        solve();
    }
}