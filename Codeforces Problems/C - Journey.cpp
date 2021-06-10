#include <bits/stdc++.h>
 
#define ll long long int
using namespace std;
const bool MOD_MODE = true;
long long int Mod = 1000000009;
#define space " "
 
 
vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};
#define vii vector<vector<int>>
#define vi vector<int>
#define pb push_back
const int mxN = 1e5 + 3;
vi g[mxN];
 
double dfs(int cur, int par, int dep) {
    int sz = 0 ;
    for(auto to : g[cur]) {
        if(to != par ) sz += 1 ;
    }
    if(sz == 0 ) {
        return dep ;
    }
    double ans = 0;
    for (auto to : g[cur]) {
        if (to == par) continue;
        ans += ((1.0/(sz)) * dfs(to, cur, dep + 1));
    }
    return ans;
}
 
int main() {
    cout << fixed << setprecision(20) ;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout << dfs(0, -1, 0) << endl;
 
 
}
