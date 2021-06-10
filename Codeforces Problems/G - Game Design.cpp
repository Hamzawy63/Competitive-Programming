#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define endll "\n"
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll INF = 301;
const int N = 2005;
const int MOD = 1e9 + 7;
const int maxN = 1e5 + 3;
#define space " "
#define PI (double)(atan(1)*4)
#define pb push_back
vector<set<int>> g(maxN);
vector<int> d(maxN);
int n;
 
int dfs(int cur, int par = -1) {
    int ans = 1;
    for (auto to : g[cur]) {
        if (to != par) {
            ans += dfs(to , cur );
        }
    }
    return d[cur] = ans;
}
 
int get_centroid(int cur, int size, int par = -1) {
    for (auto to : g[cur]) {
        if (to == par) continue;
        if (d[to] > size / 2) {
            return get_centroid(to, size, cur);
        }
    }
    return cur;
}
 
vector<char> ans;
 
void assign(int cur, int sz, char label) {
    if (sz == 1) {
        ans[cur] = label;
        return;
    }
    dfs(cur, -1);
    int centroid = get_centroid(cur, sz, -1);
    dfs(centroid,-1) ;
    ans[centroid] = label;
    // go to all children -
    for (auto to : g[centroid]) {
//        g[cur].erase(to) ; // to get rid of stupid iterators problems :
        g[to].erase(centroid) ;
        assign(to , d[to] , label+1) ;
    }
}
 
int main() {
    cin >> n;
    ans.resize(n) ;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;v-- ;
        g[u].insert(v);
        g[v].insert(u);
    }
    assign(0 , n , 'A') ;
    for(auto v : ans) {
        cout << v << space ;
    }
    cout << '\n' ;
}
