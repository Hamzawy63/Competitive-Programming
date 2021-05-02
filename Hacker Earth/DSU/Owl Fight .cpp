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
const int maxN = 1e5 + 3;
vector<int> p(maxN);

int find(int a) {
    if (p[a] == a) return a;
    else return p[a] = find(p[a]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa > bb) {
        p[bb] = aa;
    } else {
        p[aa] = bb;
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        merge(u, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int k1 = find(u);
        int k2 = find(v);
        if (k1 == k2) {
            cout << "TIE" << endl;
        } else {
            if (k1 > k2) {
                cout << u + 1 << endl;
            } else {
                cout << v + 1 << endl;
            }
        }
    }
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