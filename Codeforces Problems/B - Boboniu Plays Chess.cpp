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
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = 1000000007;
 
void solve() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    vector<pair<int, int>> res = {{sx, sy}};
    for (int i = n; i > 0; i--) {
        if (i == sx) continue;
        else res.pb({i, sy});
    }
    int cnt = 1 ;
    for (int col = 1; col <= m; col++) {
        if(col == sy) continue;
        if (cnt % 2 == 1) {
            for (int raw = 1; raw <= n; raw++) res.pb({raw, col});
        } else {
            for (int raw = n; raw >= 1; raw--) res.pb({raw, col});
        }
        cnt ++ ;
    }
    for(auto p : res) {
        cout << p.ff <<space << p.ss  <<endl;
    }
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
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
