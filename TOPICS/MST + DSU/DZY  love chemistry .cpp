#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second

const int maxN = 52;
vector<int> par(maxN), size(maxN);

int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
    size[bb] += size[aa];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        merge(u, v);
    }
    ll ans = 1;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (!st.count(find(i))) {
            st.insert(find(i));
            ans = ans * (1LL << (size[find(i)] - 1));
        }
    }
    cout << ans << endl;
}

int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}