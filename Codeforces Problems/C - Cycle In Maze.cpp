#include <bits/stdc++.h>
/*
Created on 5/10/2021 by Hamza Hassan:
*/
using namespace std;
typedef long long int ll;
#define space " "
bool debug = false;
vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, -1, 1, 0};
vector<char> res = {'D', 'L', 'R', 'U'};
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n + 3);
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }
 
    vector<vector<int>> dis(n, vector<int>(m,  -1 ));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    dis[sx][sy] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int i = cur.first;
        int j = cur.second;
        for (int d = 0; d < 4; d++) {
            int ii = i + dx[d];
            int jj = j + dy[d];
            if (ii >= 0 && jj >= 0 && ii < n && jj < m && a[ii][jj] != '*' && dis[ii][jj] == -1) {
                dis[ii][jj] = dis[i][j] + 1;
                q.push({ii, jj});
            }
        }
    }
    for(int i=0;i<n;i++)
    if (k % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    string ans;
    for (int i = 0; i < k; i++) {
        for (int d = 0; d < 4; d++) {
            int ii = sx + dx[d];
            int jj = sy + dy[d];
            if ((ii >= 0) && (ii < n) && (jj >= 0) && (jj < m) && (a[ii][jj] != '*')) {
                if (1 + dis[ii][jj] + i <= k) {
                    sx = ii;
                    sy = jj;
                    ans += res[d];
                    break;
 
                }
            }
        }
    }
    if ((int) ans.size() != k) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans << endl;
}
 
int main() {
    debug = true;
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
