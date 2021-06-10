#include <bits/stdc++.h>
/*
Created on 4/7/2021 by Hamza Hassan:
*/
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
 
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
 
 
int num_not_divisible_by_p(int L, int R, int P) {
    if (L == 1) {
        return R - (R / P);
    } else {
        int first = num_not_divisible_by_p(1, R, P);
        int second = num_not_divisible_by_p(1, L - 1, P);
        return first - second;
    }
}
 
void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> L(n);
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }
//    for (int i = 0; i < n; i++) {
//        cerr << L[i] << space << R[i] << space  << num_not_divisible_by_p(L[i], R[i], p) << endl;
//    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int nxt = i + 1;
        if (nxt == n) nxt = 0;
 
        int first = num_not_divisible_by_p(L[i], R[i], p);
        int second = num_not_divisible_by_p(L[nxt], R[nxt], p);
        double all_pairs = (R[i] - L[i] + 1) * double(R[nxt] - L[nxt] + 1);
        double pr = 1 - (first * (double) second) / all_pairs;
        ans += (pr) * 2000;
    }
    cout << fixed << setprecision(20);
    cout << ans << endl;
}
 
int main() {
    bool debug = false;
 
    if (debug) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
