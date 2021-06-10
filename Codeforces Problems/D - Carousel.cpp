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
#define MOD (int)(998244353  )
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
 
int inverse(ll, ll);
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
int powmod(ll a, ll b, ll mod) {
    //if (b < 0) return inverse(powmod(a, -1 * b));
    a %= mod;
    // b %= (mod - 1);
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
 
int inverse(ll a, ll primemod) {
    return powmod(a, 500000002, primemod);
}
 
int nxt() {
    int x;
    cin >> x;
    return x;
}
 
int lcm(int a, int b) {
    return a * 1ll / __gcd(a, b) * b;
}
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
//==================
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n + 1);
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }
        a[n] = a[0];
        int superPower = -1;
        for (int i = 1; i <= n; i++) if (a[i] == a[i - 1]) superPower = i;
        for (int i = 0; i < n; i++) a[i] = min(i % 2 + 1, (int) st.size());
        int res = 1;
        if (st.size() > 1) {
            if (n % 2 == 0 || superPower != -1) res = 2;
            else res = 3;
        }
        cout << res << endl;
        if (res == 3) a[0] = 3; else a[0] = 1;
        int size = st.size();
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == 3 || a[i - 1] == 1) a[i] = 2;
            else a[i] = 1;
            if (res == 2 && i == superPower && n % 2 == 1) a[i] = a[i - 1];
            a[i] = min(a[i], size);
        }
        if (res == 3)
            a[0] = 3;
        else
            a[0] = a[n];
        for (int i = 0; i < n; i++) cout << a[i] << space;
        cout << endl;
    }
    return 0;
}
 
