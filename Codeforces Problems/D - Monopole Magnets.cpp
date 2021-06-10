#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
const int maxN = 1001;
int vis[maxN][maxN];
char in[maxN][maxN];
int n, m;
 
void dfs(int i, int j) {
    if (in[i][j] == '.')
        return;
    if (i < 0 || j < 0)
        return;
    if (i == n || j == m)
        return;
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i - 1, j);
    dfs(i, j - 1);
}
 
bool invalid() {
    for (int i = 0; i < n; i++) {
        bool f = false, dot = false;
        for (int j = 0; j < m; j++) {
            if (in[i][j] == '#') {
                if (f && dot) {
                    cerr << "bad at " << i << space << j << endl;
                    return true;
                } else f = 1;
            } else if (in[i][j] == '.' && f) dot = true;
        }
    }
    for (int i = 0; i < m; i++) {
        bool f = false, dot = false;
        for (int j = 0; j < n; j++) {
            if (in[j][i] == '#') {
                if (f && dot) {
                    cerr << "bad at " << i << space << j << endl;
                    return true;
                } else f = 1;
            } else if (in[j][i] == '.' && f) dot = true;
        }
    }
    return false;
}
 
void solve() {
    cin >> n >> m;
    bool cols = false, raws = false;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bool isthereNorth = false;
        for (int j = 0; j < m; j++) {
            in[i][j] = s[j];
            if (in[i][j] == '#') {
                isthereNorth = true;
            }
            vis[i][j] = 0;
        }
        if (!isthereNorth)raws = true;
    }
    for (int i = 0; i < m; i++) {
        bool isThereNorth = false;
        for (int j = 0; j < n; j++) {
            if (in[j][i] == '#')
                isThereNorth = true;
        }
        if (!isThereNorth) cols = true;
    }
    if (cols ^ raws) {
        cout << -1 << endl;
        return;
    }
    if (invalid()) cout << -1 << endl;
    else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (in[i][j] == '#' && !vis[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
 
 
}
 
//cout << "Case #" << i << ": ";
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
