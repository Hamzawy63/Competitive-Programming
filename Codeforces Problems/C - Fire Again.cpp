#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
 
void solve() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<pair<int, int>> all(k);
    for (int i = 0; i < k; ++i) {
        cin >> all[i].ff >> all[i].ss;
        all[i].ff--;
        all[i].ss--;
    }
    vector<vector<int>> g(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int kk = 0; kk < k; kk++) {
                g[i][j] = min(g[i][j], abs(i - all[kk].ff) + abs(j - all[kk].ss));
            }
        }
    }
    int res = -1;
    pi ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] > res ) {
                res = g[i][j] ;
                ans = {i,j};
            }
        }
    }
    cout << ans.ff + 1 << space << ans.ss + 1 << endl;
 
}
 
int main() {
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
