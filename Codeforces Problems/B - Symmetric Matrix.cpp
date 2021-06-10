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
#define mp make_pair
#define ar array
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
const int maxN = 3e5 + 3;
const int inf = 2e9;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar<int, 4>> a;
    bool ok1 = false, ok2 = false;
    for (int i = 0; i < n; i++) {
        int aa, b, c, d;
        cin >> aa >> b >> c >> d;
        if (b == c) ok1 = true;
        a.push_back({aa, b, c, d});
    }
    if ((m * m) % 4 != 0) {
        cout << "NO" << endl;
        return ;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][1] == a[j][2] && a[i][2] == a[j][1]) ok2 = true;
        }
    }
    if (ok1 && (m == 2)) {
        cout << "YES" <<endl;
    }else if(ok1 && ok2 ) {
        cout <<"YES" <<endl;
    }else {
        cout << "NO" <<endl;
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
