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


const int maxN = 1003;
vector<string> grid(maxN);
int dp[maxN][maxN];

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].ss;
    }
    vector<int> dp(1e5 + 3, 0);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int w = a[i].ff;
        int v = a[i].ss;
        for (int j = x; j >= 0; j--) {
            if (j - w >= 0)
                dp[j] = max(dp[j], v + dp[j - w]);
        }
    }
    cout << dp[x] << endl;

    return 0;
}