#include <bits/stdc++.h>

using namespace std;
const int maxN = 2 * 1000 * 100 + 3;
vector<vector<int>> g(maxN);
vector<int> col(maxN, -1);

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

    bool ok = true;
    for(int i=0;i<n;i++){
        if(col[i] == -1 ) {
            queue<int> q;
            q.push(i);
            col[i] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                for (auto to : g[cur]) {
                    if (col[to] == -1) {
                        col[to] = col[cur] ^ 1;
                        q.push(to);
                    } else if (col[to] == col[cur]) {
                        ok = false;
                        goto FINISH;
                    }
                }
            }
        }
    }
    FINISH:
    if (!ok) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i=0;i<n;i++) {
            cout << col[i] + 1 << " ";
        }
        cout << endl;
    }

}
