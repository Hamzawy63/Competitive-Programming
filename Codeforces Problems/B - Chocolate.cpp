#include <bits/stdc++.h>
 
#define ll long long int
using namespace std;
const bool MOD_MODE = true;
long long int Mod = 1000000009;
#define space " "
 
 
vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};
#define vii vector<vector<int>>
#define vi vector<int>
#define pb push_back
 
template<class type>
class Matrix {
    int n, m;
public:
    vector<vector<type>> mat;
 
 
    Matrix(vector<vector<type>> a) {
        this->mat = a;
        this->n = (int) a.size();
        this->m = (int) a[0].size();
    }
 
 
public:
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        mat.resize(n, vector<type>(m));
    }
 
    Matrix<type> operator*(Matrix o) {
        // n * m // m * l
        vector<vector<type>> a = mat;
        vector<vector<type>> b = o.mat;
        assert(m == (int) b.size());
        vector<vector<type>> ans(n, vector<type>(b[0].size()));
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) b[0].size(); j++) {
                ans[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    if (!MOD_MODE) {
                        ans[i][j] += (a[i][k] * b[k][j]);
                    } else {
                        ans[i][j] += (a[i][k] * 1LL * b[k][j]) % Mod;
                        ans[i][j] %= Mod;
                    }
                }
            }
        }
        return Matrix<type>(ans);
    }
 
 
    Matrix<type> exp(long long int b) {
        Matrix<type> ans(n, m);
        Matrix<type> base(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans.mat[i][j] = (i == j);
            }
        }
        while (b > 0) {
            if (b & 1) {
                ans = ans * base;
            }
            base = base * base;
            b >>= 1;
        }
 
        return ans;
    }
};
 
ll pow_mod(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * 1LL * a) % mod;
        }
        b >>= 1;
        a = (a * 1LL * a) % mod;
    }
    return ans;
}
 
 
int main() {
    int n;
    cin >> n;
    vi a;
    bool dirty = false;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0 && !dirty) {
            continue;
        } else {
            dirty = true;
            a.push_back(t);
        }
    }
    while (!a.empty() && a.back() == 0) a.pop_back();
    n = (int) a.size();
    bool found = false;
    ll ans = 1;
    ll cnt = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            found = true;
            ans *= max(1LL, (cnt));
            cnt = 1;
        } else {
            cnt += 1;
        }
    }
    if (!found)ans = 0;
    cout << ans << endl;
 
 
}
