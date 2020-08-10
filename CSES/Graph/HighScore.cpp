#include <bits/stdc++.h>

using namespace std;
const int maxN = 2502;
typedef long long int ll;
const ll INF = 10000000000000000;
#define tuble pair<int,pair<int,ll>>
#define pi pair<int,int>
struct Edge {
    int u, v;
    ll cost;
};
vector<Edge> edge_list;
vector<vector<int>> g;
vector<vector<int>> g2; // graph with the direction of edges reversed
vector<ll> d(maxN, INF);
vector<int> vis(maxN, 0); // detect if the node i can reach the n-1 vertex or not :)
vector<int> vis2(maxN, 0); // detect if the node 0 can reach the node i or not  :)

void dfs(int cur, vector<int> &vis ,vector<vector<int>> &g) {
    vis[cur] = 1;
    for (auto to : g[cur]) {
        if (!vis[to]) dfs(to, vis , g );
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int n, m;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;
        v--;
        g[u].push_back(v);
        g2[v].push_back(u);
        edge_list.push_back({u, v, -1 * cost});
    }
    d[0] = 0;
    dfs(n - 1, vis, g2);
    dfs(0, vis2 , g)  ;
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edge_list) {
            // cerr << "visit u = " << edge.u << " v = " << edge.v << endl;
            if (d[edge.v] > d[edge.u] + edge.cost) {
                d[edge.v] = d[edge.u] + edge.cost;
            }
        }
    }
    bool ok = true;
    for (auto edge : edge_list) {
        if (d[edge.v] > d[edge.u] + edge.cost) { // This means that the edge v  is part of a cycle whose weight is increasing
            if (vis[edge.u] && vis2[edge.u]) ok = false;
        }
    }

    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << -1 * d[n - 1] << endl;
    }

}
