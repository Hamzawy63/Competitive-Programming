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
//vi dx = {-1, 0, 0, 1};
//vi dy = {0, -1, 1, 0};
 
struct Point {
    int x, y;
    int idx;
};
 
bool comp1(const Point &p1, const Point &p2) {
    return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y);
}
 
bool comp2(const Point &p1, const Point &p2) {
    return make_pair(p1.y, p1.x) < make_pair(p2.y, p2.x);
}
 
const int maxN = 1e5 + 4;
vector<pair<int, ll>> g[maxN];
 
void solve() {
    int nn, m;
    cin >> nn >> m;
    int sx, sy, fx, fy;
    vector<Point> a(m);
    set<pair<int, ll>> st;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v, i + 1};
    }
    for (int i = 0; i < m; i++) {
        int xx = a[i].x;
        int yy = a[i].y;
        int idx = a[i].idx;
        ll d = min(abs(sx - xx), abs(sy - yy));
        // cerr << d << endl;
        g[0].push_back({idx, d});
        g[idx].push_back({0, d});
 
        d = abs(fx - xx) + abs(fy - yy);
        g[m + 1].push_back({idx, d});
        g[idx].push_back({m + 1, d});
    }
    int s2f = abs(fx - sx) + abs(fy - sy);
    g[0].push_back({m+1 , s2f}) ; 
    g[m+1].push_back({0  , s2f }) ;
    for (int tt = 0; tt < 2; tt++) {
        if (tt == 0)
            sort(a.begin(), a.end(), comp1);
        else
            sort(a.begin(), a.end(), comp2);
 
        for (int i = 0; i < m - 1; i++) {
            Point u = a[i];
            Point v = a[i + 1];
            ll cost = min(abs(u.x - v.x), abs(u.y - v.y));
            int i1 = u.idx;
            int i2 = v.idx;
            if (!st.count(make_pair(i1, i2))) {
                g[i1].push_back({i2, cost});
                g[i2].push_back({i1, cost});
                st.insert({i1, i2});
                st.insert({i2, i1});
            }
        }
    }
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;
    const ll inf = 1e18;
    vector<ll> d(m + 3, inf);
    d[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int cur = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();
        if (d[cur] != cost) continue;
        for (auto adj : g[cur]) {
            int to = adj.first;
            ll w = adj.second;
            if (d[to] > d[cur] + w) {
                d[to] = d[cur] + w;
                pq.push({d[to], to});
            }
        }
    }
    cout << d[m + 1] << endl;
 
}
 
 
int main() {
#ifdef _DEBUG
    freopen("hello.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
