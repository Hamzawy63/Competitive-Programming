#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
int n, m;
int maxN = 1000 + 3;
vector<string> g;
vector<pair<int, int>> connected;
vii dp(maxN, vi(maxN, 0));
vii type(maxN, vi(maxN, 0));
vii vis(maxN, vi(maxN, 0));
 
bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}
 
int cnt = 0;
 
void dfs(int i, int j) {
    connected.pb({i, j});
    vis[i][j] = 1;
    type[i][j] = cnt;
    for (int d = 0; d < 4; d++) {
        int new_i = i + dx[d];
        int new_j = j + dy[d];
        if (valid(new_i, new_j) && !vis[new_i][new_j] && g[new_i][new_j] == '.') {
            dfs(new_i, new_j);
        }
    }
 
}
 
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        g.pb(s);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] == '.') {
                dfs(i, j);
                cnt++;
                int sz = (int) connected.size();
                for (auto p : connected)
                    dp[p.ff][p.ss] = sz;
                connected.clear();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') cout << g[i][j];
            else {
                int ans = 1;
                unordered_set<int> st;
                for (int d = 0; d < 4; d++) {
                    int new_i = i + dx[d];
                    int new_j = j + dy[d];
                    if (valid(new_i, new_j) && g[new_i][new_j] == '.' && !st.count(type[new_i][new_j])) {
                        ans += dp[new_i][new_j];
                        st.insert(type[new_i][new_j]) ;
                    }
                }
                cout << ans%10 ;
            }
        }
        cout << endl;
    }
 
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
