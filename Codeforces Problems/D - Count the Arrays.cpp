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
int inverse(int ) ;
//====================================================================================================
int powmod(ll a, ll b) {
    if(b < 0 ) return inverse(powmod(a , -1 * b ));
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
int addmod(int a , int b) {
    return (a + b ) % MOD;
}
int submod(int a , int b) {
    return (a - b ) % MOD;
}
int mulmod(int a , int b) {
    return ( a * 1ll * b ) % MOD;
}
int inverse(int a ) {
    return powmod(a , MOD - 2 ) ;
}
int divmod(int a , int b) {
    return mulmod(a , inverse(b)) ;
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
   int n , m ;
   cin >> n >> m ;
   int fac[m+ 1] ;
   fac[0] = 1 ;
   int inv[m+1] ;
   inv[0] = 1 ;
   for(int i = 1 ; i <= m ; i++ ){
       fac[i] = mulmod(fac[i-1] , i);
       inv[i] = inverse(fac[i]) ;
   }
//   int num = fac[m];
//   int dom = mulmod(fac[m - n ])
   int com = mulmod(mulmod(inv[n-1] , inv[m- n +1] ) , fac[m]) ;
   cout << mulmod(com , mulmod(powmod(2 , n-3) , n-2)) ;
 
 
 
    return 0;
}
