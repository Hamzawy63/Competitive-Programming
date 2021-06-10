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
double dp[1002][1002];
 
double r(int n, int d) {
    return (n / (double) d);
}
 
double solve(int w, int b) {
    if (w < 0 || b < 0) return 0;
    if (w == 0 && b == 0) return dp[w][b] = 0;
    else if (w == 0) return dp[w][b] = 0;
    else if (b == 0) return dp[w][b] = 1;
    if (dp[w][b] != -1) return dp[w][b];
 
    double pwin = r(w, w + b);
    double d1 = solve(w, b - 3);
    double d2 = solve(w - 1, b - 2);
    if (abs(d1) > 0) d1 *= r(b - 1, w + b - 1) * r(b - 2, w + b - 2) * r(b, w + b);
    if (abs(d2) > 0) d2 *= r(b - 1, w + b - 1) * r(w, w + b - 2) * r(b, w + b);
 
    return dp[w][b] = pwin + d1 + d2;
}
 
void solve() {
    int w, b;
    cin >> w >> b;
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= b; j++) {
            dp[i][j] = -1;
        }
    }
    cout << setprecision(20) << solve(w, b) << endl;
//    for (int i = 0; i <= w; i++) {
//        for (int j = 0; j <= b; j++) {
//            cout << setprecision(3) << dp[i][j] << space;
//        }
//        cout << endl;
//    }
 
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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
