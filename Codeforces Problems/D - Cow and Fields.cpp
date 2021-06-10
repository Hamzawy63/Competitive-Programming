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
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
int n, m, k;
const int N = 2 * 100000;
vector<int> g[N + 3];
vi dpe(N), dps(N);
vi vis(N);
 
void bfs(int cur, vector<int> &a) {
    for (int i = 0; i < n; i++) vis[i] = 0;
    int ctr = 0;
    queue<int> q;
    q.push(cur);
    vis[cur] = 1;
    a[cur] = 0;
    while (!q.empty()) {
        ctr++;
        int sz = (int) q.size();
        while (sz--) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                    a[v] = ctr;
                }
            }
        }
    }
}
 
bool compare(int a, int b) {
    if (dps[a] < dps[b]) return true;
    else if (dps[a] == dps[b]) {
        return dpe[a] < dpe[b];
    }
    return false;
}
 
void solve() {
    cin >> n >> m >> k;
    vector<int > special(k);
    for (int i = 0; i < k; i++) {
        cin >> special[i];
        special[i]--;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs(0, dps);
    bfs(n - 1, dpe);
//
//    for (int i = 0; i < n; i++) cerr << dps[i] << space;
//    cerr << endl;
//    for (int i = 0; i < n; i++) cerr << dpe[i] << space;
//    cerr << endl;
 
 
    sort(special.begin(), special.end() , compare);
//    for (int i = 0; i < k; i++) {
//        cerr << special[i] << space;
//    }
//    cerr << endl;
    int ans = dps[n-1];
    int ans2 = -1 ;
    for (int i = 1; i < k; i++) {
        int n2 = special[i];
        int n1 = special[i - 1];
        ans2 = max(ans2, min(dps[n1], dps[n2]) + 1 + min(dpe[n1], dpe[n2]));
    }
    cout << min(ans , ans2) << endl;
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
 
 
//       ababkamts
//    t-> bbk
//    u->aaa
