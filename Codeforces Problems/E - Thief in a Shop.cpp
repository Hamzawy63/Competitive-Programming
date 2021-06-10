#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
//#define _DEBUG
int N = 1000000;
vector<int> dp(N + 1, 1001);
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    dp[a[0] * k] = 0;
    for (int i = a[0] * k; i < N; i++) {
        if (dp[i] <= k) {
            for (int j = 0; j < n; j++) {
                if (i + a[j] - a[0] <= N) {
                    dp[i + a[j] - a[0]] = min(dp[i + a[j] - a[0]], dp[i] + 1);
                }
            }
        }
    }
    for (int i = a[0] * k; i <= N; i++) {
        if (dp[i] <= k) cout << i << space;
    }
    cout << endl;
 
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
 
}
