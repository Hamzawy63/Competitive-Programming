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
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), f(1e6 + 3, 0), f2(1e6 + 3, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= m) {
            f[a[i]]++;
            f2[a[i]]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!f2[i]) continue;
        for (int j = i + i; j <= m; j += i) {
            f[j] += f2[i];
        }
    }
    int ans = 0;
    int num = 0;
    for (int i = 1; i <= m; i++) {
        if (f[i] > ans) {
            num = i;
            ans = f[i];
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if ((ans != 0) && (num % a[i] == 0)) {
            res.push_back(i + 1);
        }
    }
    if (num == 0) num = 1;
    cout << num << space << (int) res.size() << endl;
    for (auto v : res) cout << v << space;
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
