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
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
 
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vi res(n);
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != last) {
            res[i] = a[i];
            last = a[i];
        } else if (b[i] != last) {
            res[i] = b[i];
            last = b[i];
        } else {
            res[i] = c[i];
            last = c[i];
        }
    }
    for (int v : {a[n - 1], b[n - 1], c[n - 1]}) {
        if (v != res[n - 2] && v != res[0]) {
            res[n - 1] = v;
            break; 
        }
    }
    for(auto v : res) {
        cout << v<< space ;
    }
    cout << endl;
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
