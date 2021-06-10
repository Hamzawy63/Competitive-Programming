#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
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
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
vector<int> g[2 * 1000 * 100 + 3];
vi deg ;
vi lvl ;
vector<pi> edges ;
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    deg.clear()  ;
    lvl.clear() ; 
    deg.resize(n , 0 ) ;
    lvl.resize(n ,  0) ;
    edges.clear() ;
 
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            g[a].pb(b);
            deg[b]++;
        } else if (t == 0) {
            edges.pb({a, b});
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    int next = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        lvl[cur] = next++;
        for (auto to : g[cur]) {
            deg[to]--;
            if (deg[to] == 0) q.push(to);
        }
    }
 
 
    if (next == n ) {
        cout << "YES" << endl;
        for (auto[u, v] : edges) {
            if (lvl[u] > lvl[v]) swap(u, v);
            cout << u + 1 << space << v + 1 << endl;
        }
        for (int i = 0; i < n; i++) {
            for (auto to : g[i]) {
                cout << i + 1 << space << to + 1 << endl;
            }
 
        }
    } else {
        cout << "NO" << endl;
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //   cout << "Case #" << i << ": ";
        solve();
    }
}
