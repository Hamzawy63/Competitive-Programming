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
int lcm(int a, int b ) {
    return a* 1ll / __gcd(a,b) *b ;
}
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
//==================
int ten[200000 + 5 ] ;
 
int main() {
   int n  ;
   cin >> n;
   ten[0] = 1 ;
   for(int i =1  ; i <= n ; i ++ ) ten[i] = (ten[i-1]* 1ll * 10) % MOD ;
   for(int i = 1 ; i < n-1  ; i++ ){
      ll middle = (n - i - 1 ) *1ll * 10 * 81 * ten[n - i - 2 ];
      middle %= MOD ;
      ll edge = 2 * 10 * 1ll * 9 *ten[n-i -1 ] ;
      edge %= MOD ;
      cout << (middle + edge)%MOD << space;
   }
   if(n>1) cout << 180 << space ;
   cout << 10 << endl; ;
}
