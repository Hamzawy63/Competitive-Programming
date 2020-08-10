#include <bits/stdc++.h>

using namespace std;
const int maxN = 503;
typedef long long int ll;
const ll INF = 10000000000000000;
vector<vector<ll>> g(maxN, vector<ll>(maxN, INF));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v],w * 1ll );
        g[v][u] = min(g[v][u] , w * 1ll) ;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == k || j == k) {
                    g[i][j] = g[i][j];
                } else if (i == j) g[i][j] = 0;
                else {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        if (g[u][v] == INF) cout << -1 << endl;
        else
            cout << g[u][v] << endl;
    }
}
