#include <bits/stdc++.h>
 
using namespace std;
 
void read(vector<int> &a, int n = -1);
 
void print(vector<int> &a, int n = -1);
 
const bool query = false;
 
 
long long int dp[5002][5002];
 
vector<long long int> a, b ; 
int n;
long long int total;
 
void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        total += a[i] * b[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = total;
    }
    long long int ans = total;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            long long int bonus = total;
            if (j - 1 >= i + 1) {
                bonus = dp[i + 1][j - 1];
            }
            bonus -= a[i] * b[i];
            bonus -= a[j] * b[j];
            bonus += a[i] * b[j];
            bonus += a[j] * b[i];
            ans = max(ans, bonus);
            dp[i][j] = bonus ;
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cerr << dp[i][j] << ' ';
//        }
//        cerr << endl;
//    }
 
    cout << ans << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    int qq = 1;
    if (query)
        cin >> qq;
    for (int i = 1; i <= qq; i++) {
        solve();
    }
}
 
 
void read(vector<int> &a, int n) {
    if (n == -1) n = a.size();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
 
void print(vector<int> &a, int n) {
    if (n == -1) {
        n = (int) a.size();
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
