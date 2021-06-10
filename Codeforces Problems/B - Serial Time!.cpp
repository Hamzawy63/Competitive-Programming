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
const vector<int> dx = {1, 0, -1, 0, 0, 0};
const vector<int> dy = {0, 1, 0, -1, 0, 0};
const vector<int> dz = {0, 0, 0, 0, 1, -1};
 
void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    char g[k + 1][n + 1][m + 1];
    int vis[k + 1][n + 1][m + 1];
    for (int kk = 0; kk < k; kk++) {
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                g[kk][i][j] = s[j];
                vis[kk][i][j] = false;
            }
        }
    }
    int x0, y0;
    cin >> x0 >> y0;x0--;y0--;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, x0, y0));
    vis[0][x0][y0] = true;
    int cnt = 1;
    while (!q.empty()) {
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();
        for (int i = 0; i < (int) dx.size(); i++) {
            int zz = z + dz[i];
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && zz >= 0 && yy >= 0 && xx < n && yy < m && zz < k) {
                if (g[zz][xx][yy] == '.' && !vis[zz][xx][yy]) {
                    vis[zz][xx][yy] = true;
                    cnt++;
                    q.push(make_tuple(zz, xx, yy));
                }
            }
        }
    }
    cout << cnt << endl ;
 
 
}
 
int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
