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
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
//==================
int main() {
     int q ;
     cin >>  q ;
     while(q-- ) {
         int n , m ;
         cin >> n >> m;
         string s ;
         cin >> s ;
         vi p(m) ;
         for(int i= 0 ; i< m ; i++) cin >> p[i] ;
         int f[30] ;
         for(int i =0 ; i < 26 ; i++ ) f[i] = 0 ;
         sort(p.begin(),p.end());
         for(int i = 0 ; i< n; i ++ ){
             int idx = lower_bound(p.begin() , p.end(), i+1) - p.begin();
             f[s[i] - 'a'] += (m - idx)+1 ;
         }
         for(int i = 0 ; i< 26 ; i++ ) cout << f[i]<< space ;
         cout << endl;
 
     }
    return 0;
}
