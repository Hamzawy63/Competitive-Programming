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
#define INF  (int)1000000000

void solve() {
    int n;
    cin >> n;
    vector<int> dp(1e6 + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i < 10) {
            dp[i] = 1;
        } else {
            int cur = i;
            while (cur > 0) {
                dp[i] = min(dp[i], 1 + dp[i - cur % 10]);
                cur /= 10;
            }
        }
    }
    cout << dp[n] <<endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
    //  freopen("output.txt", "w", stdout);
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}