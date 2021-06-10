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
    int q;
    cin >> q;
    while (q--) {
        int n , m ;
        cin >> n >> m ;
        vi a(n ) ;
        set<int> p ;
        for(int i =0  ; i< n ; i++) cin >> a[i] ;
        for(int i =0  ; i< m ; i++) p.insert(nxt()) ;
        bool ok = true ;
        for(int j =0  ; j < n ; j++) {
            for(int i = 0 ;i < n-1; i++ ){
                if(a[i] > a[i+1]) {
                    if(!p.count(i+1)) {
                        ok = false ;
                        break ;
                    }else
                        swap(a[i] , a[i+1]) ;
                }
            }
        }
        if(ok ) cout << "YES" << endl;
        else cout << "NO" <<endl;
 
 
 
    }
    return 0;
}
