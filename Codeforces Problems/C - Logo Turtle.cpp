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
const int maxN = 102;
const int maxM = 202;
const int maxK = 52;
const int maxL = 2;
int zero = 100;
int dp[maxN][maxM][maxK][maxL];
int n;
string s;
int sz;
 
int solve(int i, int x, int steps, int d) {
    if (steps > n) {
        return 0;
    }
    if (i == sz && steps == n) {
        return dp[i][x][steps][d] = 1;
    } else if (i == sz) {
        return dp[i][x][steps][d] = 0;
    }
    if (dp[i][x][steps][d] != -1) {
        return dp[i][x][steps][d];
    }
    /// cout << "Solving " << i << space << x << space << steps <<space << d <<endl;
    int ans = 0;
//    if (s[i] == 'F') {
//        if (d)
//            ans |= solve(i + 1, x + 1, steps, d);
//        else
//            ans |= solve(i + 1, x - 1, steps, d);
//    } else {
//        ans |= solve(i + 1, x, steps, !d);
//    }
 
    int delta = (d == 1) ? 1 : -1;
    for (int ch = 0; ch <= 50; ch++) {
        int change  = ch % 2;
        if (s[i] == 'F') {
            if (!change) {
                ans |= solve(i + 1, x + delta, steps + ch, d);
            } else {
                ans |= solve(i + 1, x, steps + ch, !d);
            }
        } else {
            if (!change) {
                ans |= solve(i + 1, x, steps + ch, !d);
            } else {
                ans |= solve(i + 1, x + delta, steps + ch, d);
            }
        }
//        int dd = d ^(ch % 2);
//        if (dd) {
//            if(s[i] == 'ans |= solve(i + 1, x + 1, steps + ch , dd);
//        }else {
//            ans|= solve(i+1 , x-1 , steps + ch , dd ) ;
//        }
    }
 
    // cout << ans << endl;
    return dp[i][x][steps][d] = ans;
}
 
void solve() {
    cin >> s;
    cin >> n;
    int ans = 0;
    sz = (int) s.size();
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 200; j++) {
            for (int k = 0; k <= 50; k++) {
                for (int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    solve(0, 100, 0, 1);
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j < 2; j++) {
            if (dp[sz][i][n][j] == 1) {
                ans = max(ans, abs(i - 100));
            }
        }
    }
    cout << ans << endl;
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
