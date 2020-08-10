#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000 * 100 + 3;
vector<vector<int>> g(maxN);
vector<int> vis(maxN, 0);
int st_vertex = -1, end_idx = -1;
vector<int> order(maxN, 0);

void dfs(int cur, int par = -1, int idx = 0) {
    order[idx] = cur;
    vis[cur] = 1;
    for (auto to : g[cur]) {
        if (vis[to] && to != par) {
            end_idx = idx;
            st_vertex = to;
            break;
        } else if (!vis[to]) {
            dfs(to, cur, idx + 1);
            if (st_vertex != -1) return;
        }
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
    for (int i = 0; i < n; i++) {
        if (st_vertex == -1 && !vis[i]) {
            dfs(i, -1, 0);
        }
    }
    if (st_vertex == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> res;
        for (int i = end_idx;; i--) {
            res.push_back(order[i] + 1);
            if (order[i] == st_vertex) {
                break;
            }
        }
        res.push_back(order[end_idx] + 1 );
        cout << (int) res.size() << endl;
        for (auto v : res) {
            cout << v << " ";
        }
        cout << endl;
    }


}
