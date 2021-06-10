#include <bits/stdc++.h>
/*
Created on 4/3/2021 by Hamza Hassan:
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
 
void solve() {
    cout << fixed << setprecision(20)  ; 
    int m, n;
    cin >> m >> n;
    double ans = 0;
    for (int k = 1; k <= m; k++) {
        double pr = 0;
        pr += pow((k / (double) m), n);
        pr -= pow((k - 1) / (double) m, n);
//        cout << pr << endl;
        ans += pr * k;
    }
//    cout << "last " << endl;
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
//        cout << "Case " << i << ": ";
        solve();
    }
}
