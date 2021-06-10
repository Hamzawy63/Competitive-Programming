#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const vector<int> dy = {0, 0, 1, 0, -1, 1, -1, 1, -1};
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    vector<vector<int>> rep(1e6 + 2);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        rep[vec[i]].push_back(i);
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        int s = lower_bound(rep[c].begin(), rep[c].end(), a) - rep[c].begin();
        int e = lower_bound(rep[c].begin(), rep[c].end(), b) - rep[c].begin();
        int sz = (int) rep[c].size();
        if (s == sz || rep[c][s] != a) {
            cout << a + 1 << endl;
        } else if (e == sz || rep[c][e] != b) {
            cout << b + 1 << endl;
        } else {
            if (e - s + 1 == (b - a + 1)) {
                cout << -1 << endl;
            } else {
                int ans;
                int L = s+1, R = e;
                while (L <= R) {
                    int M = (L + R) / 2;
                    if (rep[c][M] - rep[c][s] == M - s) {
                        L = M + 1;
                    } else {
                        ans = rep[c][M] - 1;
                        R = M - 1;
                    }
                }
                cout << 1 + ans << endl;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
