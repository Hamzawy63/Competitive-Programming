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
    int cnt = 0;
    vector<pair<int, int>> border;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, false));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (a[i][j] == '.') {
                    cnt++;
                    border.pb({i, j});
                }
            }
        }
    }
    if (cnt != 2) {
        cout << "invalid" << endl;
        return;
    }
    queue<pair<int, int>> q;
    q.push(make_pair(border[0].ff, border[0].ss));
    vis[border[0].ff][border[0].ss] = true;
    bool ok = false;
    while (!q.empty()) {
        int sz = (int) q.size();
        while (sz--) {
            int r = q.front().ff;
            int c = q.front().ss;
            if (r == border[1].ff && c == border[1].ss) {
                ok = true;
            }
            q.pop();
            for (int i = 0; i < 4; i++) {
                int rr = r + dx[i];
                int cc = c + dy[i];
                if (rr >= 0 && rr < n && cc >= 0 && cc < m && (a[rr][cc] == '.') && (!vis[rr][cc])) {
                    vis[rr][cc] = 1;
                    q.push({rr, cc});
                }
            }

        }
    }
    if (ok) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
}

int main() {
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}