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
const int maxN = 5002;
vector<int> a(maxN);
int dp[maxN][maxN];
 
int go(int L, int R) {
    if (L > R) return 0;
    int out = max(a[R + 1], a[L - 1]);
    int mIdx = min_element(a.begin() + L, a.begin() + R + 1) - a.begin();
    int me = a[mIdx];
    return min(R - L + 1, go(L, mIdx - 1) + go(mIdx + 1, R) + me - out);
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n+1] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << go(1, n);
 
}
 
int main() {
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
