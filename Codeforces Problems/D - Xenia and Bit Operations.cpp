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
const int maxN = (1 << 17) + 3;
int seg[4 * maxN];
int n;
int a[maxN];
 
void combine(int v, int lvl) {
    if (lvl % 2 == 0) {
        seg[v] = seg[2 * v] ^ seg[2 * v + 1];
    } else {
        seg[v] = seg[2 * v] | seg[2 * v + 1];
    }
}
 
void build(int tl = 0, int tr = (1<<n) - 1, int v = 1, int lvl = n) {
    if (tl == tr) {
        seg[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(tl, tm, 2 * v, lvl - 1);
    build(tm + 1, tr, 2 * v + 1, lvl - 1);
    combine(v, lvl);
}
 
void update(int idx, int val, int tl = 0, int tr = (1<<n) - 1, int v = 1, int lvl = n) {
    if (tl == tr) {
        seg[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm) update(idx, val, tl, tm, 2 * v, lvl - 1);
    else update(idx, val, tm + 1, tr, 2 * v + 1, lvl - 1);
    combine(v, lvl);
}
 
void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    build();
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        update(idx, val);
        cout << seg[1] << endl;
    }
 
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
