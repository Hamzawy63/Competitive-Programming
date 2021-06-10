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
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
int n, k;
 
ll powmod(ll a, ll b) {
    a %= MOD;
    b %= MOD - 1;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
 
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res % MOD;
}
 
int calc() {
    ll x = powmod(2, n) - 1;
    ll t = powmod(2, (ll) k * n) -1 ;
    ll xinverse = powmod(x, MOD - 2);
    return (xinverse * t) % MOD;
 
}
 
int main() {
 
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    cin >> s ;
    cin >> k ;
    n = s.size();
    ll t = calc() ;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' || s[i] == '5') {
            res = (res +  (powmod(2  , i ) * t) % MOD ) % MOD;
        }
    }
    cout << res << endl ;
    return 0;
}
