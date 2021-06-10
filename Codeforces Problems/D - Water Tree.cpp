#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define pb push_back
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
const int maxN = 5e5;
int seg[maxN * 4], lazy[4 * maxN];
int last[maxN + 3], mp[maxN + 3], p[maxN + 3];
int n;
vector<int> g[maxN + 3];
int timer = -1;
 
void dfs(int cur, int par = -1) {
    mp[cur] = ++timer;
    p[cur] = par;
    for (auto to : g[cur]) {
        if (to != par) {
            dfs(to, cur);
        }
    }
    last[cur] = timer;
}
 
void combine(int v) {
    seg[v] = seg[2 * v] & seg[2 * v + 1];
}
 
void push(int v, int tl, int tr) {
    if (lazy[v]) {
        lazy[v] = false;
        if (tl != tr) {
            for (auto to : {2 * v, 2 * v + 1}) {
                lazy[to] = true;
                seg[to] = 1; // this means it is colored ;
            }
        }
    }
}
 
// when we color the whole subarray ;)
void range_update(int L, int R, int tl = 0, int tr = n - 1, int v = 1) {
    if (L > R) return;
    push(v, tl, tr);
    if (L == tl && R == tr) {
        seg[v] = 1;
        if (tl != tr) {
            lazy[v] = true;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    range_update(L, min(R, tm), tl, tm, 2 * v);
    range_update(max(tm + 1, L), R, tm + 1, tr, 2 * v + 1);
    combine(v);
}
 
void point_update(int idx, int tl = 0, int tr = n - 1, int v = 1) {
    push(v, tl, tr);
    if (tl == tr) {
        seg[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm) point_update(idx, tl, tm, v * 2);
    else point_update(idx, tm + 1, tr, v * 2 + 1);
    combine(v);
}
 
// just check is there is a zero in this damn subarray
int query(int L, int R, int tl = 0, int tr = n - 1, int v = 1) {
    if (L > R) {
        return 1;
    }
    push(v, tl, tr);
    if (L == tl && R == tr) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    int x = query(L, min(R, tm), tl, tm, 2 * v);
    int y = query(max(tm + 1, L), R, tm + 1, tr, 2 * v + 1);
//    combine(v);
    return x & y;
}
 
 
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
#ifdef BUG
    for(int i=0;i<n;i++){
        cerr << i << space  ;
    }
    cerr << endl;
    for(int i=0;i<n;i++){
        cerr << mp[i] << space ;
    }
    cerr << endl;
    for(int i=0;i<n;i++){
        cerr << last[i] << space ;
    }
    cerr << endl;
#endif
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int t, v;
        scanf("%d %d", &t, &v);
        v--;
        int L = mp[v];
        int R = last[v];
        if (t == 1) {
            int chk = query(L, R);
            if (!chk && p[v] != -1) {
                int PL = mp[p[v]];
                point_update(PL);
            }
            range_update(L, R);
        } else if (t == 2) {
            point_update(L);
        } else if (t == 3) {
            printf("%d\n", query(L, R));
            //fflush(stdout);
        }
    }
 
 
}
 
int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
