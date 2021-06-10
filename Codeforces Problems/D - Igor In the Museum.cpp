#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
int n, m, k;
int dp[1001][1001];
char g[1001][1001];
int vis[1001][1001];
 
bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    return dp[i][j] != -1;
}
 
ll cur = 0;
 
void dfs(int i, int j) {
    cur += dp[i][j];
    for (int d = 0; d < 4; d++) {
      //  cerr << debug(i + dx[d]) << space << debug(j + dy[d]) << endl;
        if (valid(i + dx[d], j + dy[d]) && vis[i+dx[d]][j+dy[d]] == 0) {
            vis[i + dx[d]][j + dy[d]] = 1;
            dfs(i + dx[d], j + dy[d]);
        }
    }
}
 
void change(int i, int j) {
    for (int d = 0; d < 4; d++) {
        if (valid(i + dx[d], j + dy[d]) && vis[i+dx[d]][j+dy[d]] == 1) {
            vis[i + dx[d]][j + dy[d]] = 2;
            dp[i+dx[d]][j+dy[d]] = cur;
            change(i + dx[d], j + dy[d]);
        }
    }
}
 
void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
            if (g[i][j] == '*') {
 
                dp[i][j] = -1;
                continue;
            }
            if (i > 0 && g[i - 1][j] == '*') dp[i][j]++;
            if (j > 0 && g[i][j - 1] == '*') dp[i][j]++;
            if (i < n && g[i + 1][j] == '*') dp[i][j]++;
            if (j < m && g[i][j + 1] == '*') dp[i][j]++;
        }
    }
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) vis[i][j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] == '.') {
                vis[i][j] = 1;
                cur = 0;
                dfs(i, j);
                change(i , j ) ;
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cerr << dp[i][j] << space;
//        }
//        cerr << endl;
//    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << dp[a][b] << endl;
    }
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
