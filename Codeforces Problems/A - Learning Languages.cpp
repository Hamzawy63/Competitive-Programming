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
int maxN = 102;
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
    int n, m;
    cin >> n >> m;
    vector<int> last(m);
    for (int i = 0; i < m; i++)last[i] = -1;
    for (int i = 0; i < n; i++)par[i] = i;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 0) {
            cnt++;
        }
        while (k--) {
            int l;
            cin >> l;
            l--;
            if (last[l] == -1) {
                last[l] = i;
            } else {
                merge(last[l], i);
            }
        }
    }
    if (cnt == n) {
        cout << n << endl;
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i) ans++;
    }
    cout << ans - 1 << endl;
 
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
