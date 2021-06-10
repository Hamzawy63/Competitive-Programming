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
const int maxN = 4 * 100000 + 1;
vector<ll> seg(4 * 4 * 100000);
vi col(maxN);
vii g(4 * 100000);
vi L(maxN), R(maxN), p;
int timer = -1;
 
void dfs(int cur, int par = -1) {
    timer++;
    p.pb(cur);
    L[cur] = timer;
    for (auto to : g[cur]) {
        if (to == par) continue;
        else dfs(to, cur);
    }
    R[cur] = timer;
}
 
vi marked(4 * 4 * 100000);
 
void push(int v) {
    if (marked[v]) {
        //seg[v * 2] = seg[v * 2 + 1] = seg[v];
        if (2 * v < (int) (seg.size())) {
            seg[2 * v] = seg[v];
            marked[2 * v] = true;
        }
        if (2 * v + 1 < (int) seg.size()) {
            seg[2 * v + 1] = seg[v];
            marked[2 * v + 1] = true;
        }
        //if(2 * v < (int)seg.size()) marked[v * 2] = marked[v * 2 + 1] = true;
        marked[v] = false;
    }
}
 
void build(int tl, int tr, int v) {
    if (tl == tr) {
        seg[v] = (1LL << col[p[tl]]);
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, 2 * v);
        build(tm + 1, tr, 2 * v + 1);
        seg[v] = seg[2 * v] | seg[2 * v + 1];
    }
}
 
int new_update_val;
 
void update(int tl, int tr, int v, int l, int r) {
    if (l > r) return;
    if (tl == l && tr == r) {
        marked[v] = 1;
        seg[v] = (1LL << new_update_val);
        return;
    }
    push(v);
    int td = (tl + tr) / 2;
    update(tl, td, 2 * v, l, min(r, td));
    update(td + 1, tr, 2 * v + 1, max(td + 1, l), r);
    seg[v] = seg[v * 2] | seg[2 * v + 1];
}
 
ll sum(int tl, int tr, int v, int l, int r) {
    if (l > r) return 0;
    if (marked[v]) {
        push(v);
    }
    if (tl == l && tr == r) {
        return seg[v];
    }
    int td = (tl + tr) / 2;
    ll first = sum(tl, td, 2 * v, l, min(r, td));
    ll second = sum(td + 1, tr, 2 * v + 1, max(td + 1, l), r);
    return first | second;
}
 
 
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> col[i];
        col[i]--;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
#ifdef _DEBUG
    cerr << "DFS Successful " << endl;
    for (int i = 0; i < n; i++) cerr << L[i] << space;
    cerr << endl;
    for (int i = 0; i < n; i++) cerr << R[i] << space;
    cerr << endl;
#endif
    build(0, n - 1, 1);
#ifdef _DEBUG
    cerr << "Building successful " << endl;
    for (int i = 0; i < 16; i++) cerr << seg[i] << space;
    cerr << endl;
 
#endif
    for (int i = 0; i < q; i++) {
        int type, v, c;
        cin >> type >> v;
        v--;
        if (type == 1) {
            cin >> c;
            new_update_val = c - 1;
            update(0, n - 1, 1, L[v], R[v]);
        } else {
            ll res = sum(0, n - 1, 1, L[v], R[v]);
            //cerr << res << endl;
            int ans = 0;
            while (res > 0) {
                ans += res % 2;
                res /= 2;
            }
            cout << ans << endl;
        }
#ifdef _DEBUG
        cerr << "After the operation number i = " << i + 1 << endl;
        cerr << "Segment tree = [";
        for (int ii = 1; ii <= 13; ii++) cerr << seg[ii] << space;
        cerr << " ]" << endl;
 
        cerr << "marked array  = [";
        for (int ii = 1; ii <= 13; ii++) cerr << marked[ii] << space;
        cerr << " ]" << endl;
#endif
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
