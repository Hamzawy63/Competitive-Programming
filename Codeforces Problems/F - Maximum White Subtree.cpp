#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
vi g[200000 + 4];
int col[200000 + 4];
int dp[200000 + 4];
int ans[200000 + 4];
 
///*******************
int dfs(int cur, int parent) {
    vector<int> res;
    for (int i = 0; i < g[cur].size(); i++) {
        if (g[cur][i] != parent) res.pb(dfs(g[cur][i], cur));
    }
    int subres = 0;
    for (int i = 0; i < (int) res.size(); i++)
        subres += max(0, res[i]);
    return dp[cur] = subres + col[cur];
}
 
void reroot(int cur, int par) {
    ans[cur] = dp[cur];
    for (auto to : g[cur]) {
        if (to != par) {
            int a = max(dp[to], 0);
            int b = max(dp[cur], 0);
            dp[cur] -= max(dp[to], 0);
            dp[to] += max(dp[cur], 0);
            reroot(to, cur);
            dp[to] -= b;
            dp[cur] += a;
        }
    }
 
}
 
//**********************
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0)
            col[i] = -1;
        else
            col[i] = t;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0, -1);
    reroot(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << space;
    }
    cout << endl;
}
