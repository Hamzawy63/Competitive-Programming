#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
const int maxN = 3e5 + 3;
const int inf = 2e9;
set<int> g[maxN];
 
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi ans(n + 1, inf);
    for(int i=0;i<=n;i++){
        g[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        g[a[i]].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].empty())
            continue;
        else {
            int m = -1;
            int last = -1;
            g[i].insert(n);
            for (auto v : g[i]) {
                m = max(m, v - last);
                last = v;
            }
            ans[m] = min(ans[m], i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = min(ans[i - 1], ans[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == inf) ans[i] = -1;
        cout << ans[i] << space;
    }
    cout << endl;
 
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
