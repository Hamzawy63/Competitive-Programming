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
   int n ;
   cin >> n ;
   vi a(n ) ;
   for(int i = 0 ;i < n ;i ++) cin >> a[i] ;
   string res = "" ;
   int l = 0 ;
   int r = n-1 ;
   int last = -1 ;
   while(a[l] != a[r]) {
       if(a[l] > last && a[l] < a[r]) {
           res += 'L';
           last = a[l] ;
           l++ ;
       }else if (a[r] > last && a[r] < a[l]) {
           res += 'R';
           last = a[r] ;
           r--;
       }else break ;
   }
   int lastt = last  ;
   string rl = "" ;
   while(l < n && a[l] > lastt) {
       rl += 'L' ;
       lastt = a[l++] ;
   }
    lastt =last ;
   string rr = "" ;
   while(r > -1 && a[r] > lastt ) {
       rr += 'R' ;
       lastt = a[r--] ;
   }
   cout << res.size() + max(rr.size() , rl.size()) << endl ;
   cout << res ;
   if(rr.size() > rl.size()) cout << rr ;
   else cout << rl ;
   cout << endl;
 
    return 0;
}
 
