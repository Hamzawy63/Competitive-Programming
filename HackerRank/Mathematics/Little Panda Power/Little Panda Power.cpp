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
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
const double inf = 1e9;
const int maxN = 1e6;


int powmod(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        b >>= 1;
        a = (a * 1LL * a) % mod;
    }
    return ans;
}

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Fuck , Inverse doesn't exist";
    else {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        return res ;
       // cout << "Modular multiplicative inverse is " << res;
    }
    return -1 ;
}


void solve() {
    int a, b, x;
    cin >> a >> b >> x;
    if (b > 0) {
        cout << powmod(a, b, x) << endl;
    } else if (b < 0) {
        int inverse = modInverse(a, x);
        cout << powmod(inverse, -1 * b, x) << endl;
    } else {
        if (x > 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
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