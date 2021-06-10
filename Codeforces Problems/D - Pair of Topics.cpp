#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <unordered_map>
 
typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(6)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define MAT_SIZE 5
 
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
//====================================================================================================
//====================================================================================================
int powmod(ll a, ll b) {
    a %= MOD;
    b %= (MOD - 1);
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
 
vvll mul(vvll a, vvll b) {
    int n = a.size();
    int m = b[0].size();
    // std::vector<std::vector<int>> matrix(M, std::vector<int>(N, default_value));
    vvll res(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < (int) b.size(); k++) {
                res[i][j] += (a[i][k] * 1ll * b[k][j]) % (MOD - 1);
                res[i][j] %= (MOD - 1);
            }
 
        }
    }
    return res;
}
 
int log(int a, int b) {
    int n = (int) sqrt(MOD + .0) + 1;
    map<int, int> vals;
    for (int p = n; p >= 1; --p)
        vals[powmod(a, p * n)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (powmod(a, q) * 1ll * b) % MOD;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
//====================================================================================================
//====================================================================================================
 
int main() {
 
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi sub(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    for (int i = 0; i < n; i++) sub[i] = b[i] - a[i];
    sort(sub.begin(), sub.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int target = -1 * sub[i];
        //cout << (lower_bound(sub.begin(), sub.end(), target) - sub.begin()) - (sub[i] < 0 ? 1 : 0) << space;
        res += (lower_bound(sub.begin(), sub.end(), target) - sub.begin());
        if (sub[i] < 0) res -= 1; // with itself
    }
    cout << res / 2 << endl; // dublicates :) 
 
 
    return 0;
}
