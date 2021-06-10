#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
void solve() {
    int n, k;
    cin >> n >> k;
    if (k > n * n) {
        cout << -1 << endl;
    } else {
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1)
                    continue;
                if (i == j) {
                    if (k) {
                        a[i][j] = 1;
                        k--;
                    }
                } else {
                    if (k >= 2) {
                        a[i][j] = 1;
                        a[j][i] = 1;
                        k -= 2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << a[i][j] << " " ;
            }
            cout << endl;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO5
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
