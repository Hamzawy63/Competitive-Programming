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
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
 
 
int powmod(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res;
}
 
int discrete_log(int a, int b, int m) {
    b %= (m - 1); // m should be prime
    // fermat ^-^
    int n = (int) sqrt(m + .0) + 1;
    map<int, int> vals;
    for (int p = n; p >= 1; --p)
        vals[powmod(a, p * n, m)] = p;
    for (int q = 0; q <= n; ++q) {
        int cur = (powmod(a, q, m) * 1ll * b) % m;
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
 
int generate_primitive_root(int p) {
    vector<int> fact;
    int phi = p - 1, n = phi;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back(n);
 
    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (size_t i = 0; i < fact.size() && ok; ++i)
            ok &= powmod(res, phi / fact[i], p) != 1;
        if (ok) return res;
    }
    return -1;
}
 
vector<vector<int >> mat_mul(vector<vector<int>> a, vector<vector<int>> b) {
    // a = n*n , b = n*n :)
    int N = a.size();
    vector<vector<int>> ans(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ans[i][j] += a[i][k] + a[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n ;
        vector<int> a(2 * n + 2);
        set<int> st;
        for (int i = 1; i <= 2 * n; i++) st.insert(i);
        for (int i = 1; i <= n; i++) {
            cin >> a[2 * i - 1];
            st.erase(a[2 * i - 1]);
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            auto it = st.upper_bound(a[2 * i - 1]);
            if (it == st.end()) {
                ok = false;
                break;
            } else {
                int val = *it;
                st.erase(val);
                a[2 * i] = val;
            }
        }
        if (!ok) cout << -1 << endl;
        else {
            for (int i = 1; i <= 2 * n; i++) cout << a[i] << space;
            cout << endl ;
        }
    }
    return 0;
}
