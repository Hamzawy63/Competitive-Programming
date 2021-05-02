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

const int maxN = 102;
vector<int> par(maxN);

int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}

void solve() {
    int n;
    cin >> n;
    vector<int> res(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
        res[i]--;
        par[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < n; i++) {
        if (d[i] + i < n) merge(i, i + d[i]);
        if (i - d[i] >= 0) merge(i, i - d[i]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (find(i) != find(res[i])) ok = false;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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