#include <bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long
 
 
const int mxN = 103;
int query = 1;
 
vector<int> g[mxN];
 
int dep[mxN];
int a[mxN];
 
void solve(int i, int j, int parent) {
    if (i > j) {
        return;
    }
    int mx = -1, mx_idx = -1;
    for (int ii = i; ii <= j; ii++) {
        if (a[ii] > mx) {
            mx = a[ii];
            mx_idx = ii;
        }
    }
    if (mx != -1) {
        g[parent].push_back(mx);
        solve(i, mx_idx - 1, mx);
        solve(mx_idx + 1, j, mx);
    }
}
 
void dfs(int cur, int depth) {
    dep[cur] = depth;
    for (auto to : g[cur]) {
        dfs(to, depth + 1);
    }
}
 
void solve() {
    int n;
    cin >> n;
    int mx, mx_idx;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) {
            mx_idx = i;
        }
        a[i]--;
 
    }
    for (int i = 0; i <= 100; i++) {
        dep[i] = 0;
        g[i].clear();
    }
    solve(0, mx_idx-1, n - 1);
    solve(mx_idx + 1, n - 1, n - 1);
    dfs(n-1 , 0 ) ;
    for (int i = 0; i < n; i++) {
        cout << dep[a[i]] << space ;
    }
    cout << endl;
 
 
}
 
int main() {
//    freopen("in" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    IO;
    int q = 1;
    if (query) cin >> q;
    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
}
