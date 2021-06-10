#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
 
void solve() {
    int n;
    cin >> n;
    vi f(55, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        f[t]++;
    }
    int ans = 0;
    for (int w = 1; w <= 100; w++) {
        int res = 0;
        for (int i = 1; i <= min(w - 1, 50); i++) {
            if(w - i > 50)continue;
            //  cerr << "w = " << w << "  i = " <<i<< endl;
            if (i == w - i) {
                res += (f[i] / 2) * 2;
            } else {
                res += min(f[i], f[w - i]);
            }
        }
        if (res != 0) {
           // cout << res/2 << endl;
            ans = max(res / 2, ans);
        }
    }
    cout << ans << endl;
}
 
//#define _DEBUG
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
