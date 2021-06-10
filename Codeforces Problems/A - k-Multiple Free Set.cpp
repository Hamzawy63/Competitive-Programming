#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define ar array
const int mxN = 1e5;
vector<int> g[mxN + 3];
vector<int> vis(mxN + 4);
int sz = 0;
 
void dfs(int cur) {
    sz++;
    vis[cur] = true;
    for (auto to : g[cur]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
}
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (mp.count(a[i] * 1LL * k)) {
            g[i].push_back(mp[a[i] * 1LL * k]);
            g[mp[a[i] * 1LL * k]].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans += (sz + 1) / 2;
            sz = 0;
        }
    }
    cout << ans <<endl;
}
