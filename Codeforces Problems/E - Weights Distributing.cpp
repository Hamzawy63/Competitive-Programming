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
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
const int INF = INT_MAX;
vector<int> g[2 * 100 * 1000+4];
void bfs(int v, vector<int> &d) {
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int adj : g[cur]) {
            if (d[adj] == INF) {
                d[adj] = d[cur] + 1;
                q.push(adj);
            }
        }
    }
 
}
 
void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    for(int i=0;i<n;i++){
        g[i] = {};
    }
    a--;
    b--;
    c--;
    vector<ll> cost(m+1);
    cost[0] = 0 ;
    for (int i = 1; i <= m; i++) cin >> cost[i];
    sort(cost.begin(), cost.end());
    for (int i = 1; i <= m; i++) cost[i] += cost[i - 1];
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    vector<int> as(n, INF), bs(n, INF), cs(n, INF);
    bfs(a, as);
    bfs(b, bs);
    bfs(c, cs);
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        if(as[i] + cs[i] + bs[i] > m) continue;
        ll total = 0;
        total +=  cost[bs[i]];
        total += cost[as[i] + cs[i] + bs[i] ];
        ans = min(total , ans ) ;
    }
    cout << ans << endl;
 
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
