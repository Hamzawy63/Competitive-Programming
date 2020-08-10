#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000 * 100 + 3;
vector<vector<int>> g(maxN);
vector<int> vis(maxN, -1);

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
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int cur = q.front();
            q.pop();
            for (auto to : g[cur]) {
                if (vis[to] == -1) {
                    vis[to] = vis[cur] + 1;
                    q.push(to);
                }
            }
        }
    }
    if (vis[n - 1] == -1) {
        cout << "IMPOSSIBLE"<< endl;
    } else {
        cout << vis[n - 1] << endl;
        int cur = n - 1;
        vector<int> ans={n-1};
        while (cur != 0) {
            for (auto to : g[cur]) {
                if (vis[to] + 1 == vis[cur]) {
                    ans.push_back(to);
                    cur = to;
                    break;
                }
            }
        }
        reverse(ans.begin() , ans.end()) ;
        for(auto v : ans) {
            cout << v+1 << " " ;
        }
        cout << endl;
    }


}
