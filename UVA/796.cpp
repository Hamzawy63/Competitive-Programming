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
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = 1000 * 1000 * 1000 + 7;


struct Graph {
    int maxN ;
    vi in, out, vis;
    vii g;
    vector<pair<int, int>> links;
    int bridges = 0, t = 1;
    Graph(int maxN) {
        this->maxN = maxN ;
        in.assign(maxN, 0);
        out.assign(maxN, INF);
        vis.assign(maxN, false);
        g.resize(maxN);
    }
    void add_directed(int u ,int v ){
        g[u].pb(v) ;
    }
    void total_dfs() {
        for(int i=0;i<maxN;i++){
            if(!vis[i]) {
                t = 1 ;
                dfs(i , -1 ) ;
            }
        }
    }
    void dfs(int cur, int par = -1) {
        vis[cur] = 1;
        in[cur] = t++;
        for (int to : g[cur]) {
            if (!vis[to]) dfs(to, cur);
        }
//    out[cur] = t;
        for (int to :g[cur]) {
            if (to == par) continue;
            out[cur] = min(out[cur], in[to]);
            out[cur] = min(out[cur], out[to]);
        }
        if (par != -1) {
            if (out[cur] > in[par]) {
                bridges++;
                links.pb({min(cur, par), max(cur, par)});
                //cerr << (char)(cur+'a') << space << (char)('a' +par) << " are bridge" << endl;
            }
        }
    }
};


void solve() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Graph g(n) ;
        for (int ts = 0; ts < n; ts++) {
            int u, m;
            scanf("%d (%d)", &u, &m);
            while (m--) {
                int v;
                scanf("%d", &v);
                g.add_directed(u,v);
            }

        }
        g.total_dfs();
        cout << g.bridges << " critical links" << endl;
        sort(g.links.begin(), g.links.end());
        for (auto p : g.links) {
            cout << p.ff << " - " << p.ss << endl;
        }
        cout << endl;

    }
}

//#define _DEBUG

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}