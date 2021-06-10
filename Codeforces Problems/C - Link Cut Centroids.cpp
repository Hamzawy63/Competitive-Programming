#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
const ll inf = 1e7;
const int maxN = 1e5 + 4;
vector<int> g[maxN];
vector<int> cnt(maxN);
vector<int> centroid_vertices;
int centroid = inf;
int n;
 
void dfs(int cur, int par = -1) {
    cnt[cur] = 1;
    int max_sub = 0;
    for (auto to : g[cur]) {
        if (to == par) continue;
        else {
            dfs(to, cur);
            max_sub = max(max_sub, cnt[to]);
            cnt[cur] += cnt[to];
        }
    }
    max_sub = max(max_sub, n - cnt[cur]);
    if (max_sub == centroid) {
        centroid_vertices.push_back(cur);
    } else if (max_sub < centroid) {
        centroid_vertices = {cur};
        centroid = max_sub;
    }
}
 
void solve() {
    cin >> n;
    centroid_vertices.clear();
    centroid = inf;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        cnt[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
//    for (int i = 0; i < n; i++) {
//        cerr << cnt[i] << " ";
//    }
//    cerr << endl;
 
    //  cerr << "Centroid = " << centroid << " cnt = " << centroid_vertices.size() << endl;
    if (centroid_vertices.size() == 1) {
        cout << g[0][0] + 1 << " " << 1 << endl;
        cout << g[0][0] + 1 << " " << 1 << endl;
    } else {
        int packup = centroid_vertices.back();
        int cur = centroid_vertices.back();
        int par = centroid_vertices.back();
        dfs(cur, -1);
        while (true) {
            int nxt = -1;
            int nxt_cnt = 0;
            for (auto to : g[cur]) {
                if (to != par) {
                    if (cnt[to] > nxt_cnt) {
                        nxt_cnt = cnt[to];
                        nxt = to;
                    }
                }
            }
            if (nxt == -1)
                break;
            else {
                par = cur;
                cur = nxt;
            }
        }
        cout << cur + 1 << " " << par + 1 << endl;
        cout << packup + 1 << " " << cur + 1 << endl;
    }
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
 
 
}
