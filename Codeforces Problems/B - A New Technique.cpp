#include <bits/stdc++.h>
 
using namespace std;
#define space " "
using ll =  long long int;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n);
    vector<set<int>> rows_hash(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            rows[i].push_back(t);
            rows_hash[i].insert(t);
        }
    }
    vector<vector<int>> cols(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            cols[i][j] = t;
        }
    }
    vector<int> &col = cols[0];
    for (int i = 0; i < n; i++) {
        int cur = col[i];
        for (int row = 0; row < n; row++) {
            if (rows_hash[row].count(cur)) {
                for (int j = 0; j < m; j++) {
                    cout << rows[row][j] << space;
                }
                cout << endl;
            }
        }
    }
 
}
 
#define LOCAL
 
int main() {
//    freopen("gift1.in", "r", stdin);
//    freopen("gift1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
}
