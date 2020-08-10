#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000 * 100 + 3;

vector<vector<int>> g(maxN);
vector<int> vis(maxN, 0);

void dfs(int cur) {
    vis[cur] = 1;
    for (int to : g[cur]) {
        if (!vis[to])dfs(to);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int par = -1, ans = 0;
    vector<int> edges;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (par == -1) {
                par = i;
            }else {
                ans++;
                edges.push_back(i);
            }
            dfs(i);
        }
    }
    cout << ans << endl;
    for (auto to : edges) cout << par+1 << " " << to + 1 << endl;


}
