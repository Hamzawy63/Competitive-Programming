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
int lcm(int a, int b ) {
    return a* 1ll / __gcd(a,b) *b ;
}
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
//==================
int main() {
    int q ;
    cin >> q ;
    while(q-- ){
        int a , b , c ;
        cin >> a >> b >> c ;
        int ans = a + b -2;
        vi res = {1,1,c};
        for(int i = 1 ; i <= 2 * (int)pow(10 , 4) ; i++ ){
            for(int j = 1 ; j * 1ll * j <= i ; j++ ){
                if(i%j == 0 ) {
                    int aa = j , bb = i ;
                    int lc = lcm(aa , bb) ;
                    int cc1 = max(lc , (c/lc) * lc ) ;
                    int cc2 = ceil(c/(double)lc ) * lc ;
                    int cc ;
                    if(abs(c - cc1) < abs(c - cc2)) cc = cc1 ;else cc = cc2 ;
                    int possibleAns = abs(aa - a ) + abs(bb - b ) + abs(cc - c ) ;
                    if(possibleAns < ans) {
                        ans = abs(aa - a ) + abs(bb - b ) + abs(cc - c ) ;
                        res = {aa ,bb , cc};
                    }
                }
                if(i%j == 0 ) {
                    int aa = i/j , bb = i ;
                    int lc = lcm(aa , bb) ;
                    int cc1 = max(lc , (c/lc) * lc ) ;
                    int cc2 = ceil(c/(double)lc ) * lc ;
                    int cc ;
                    if(abs(c - cc1) < abs(c - cc2)) cc = cc1 ;else cc = cc2 ;
                    int possibleAns = abs(aa - a ) + abs(bb - b ) + abs(cc - c ) ;
                    if(possibleAns < ans) {
                        ans = abs(aa - a ) + abs(bb - b ) + abs(cc - c ) ;
                        res = {aa ,bb , cc};
                    }
                }
 
            }
        }
        cout << ans << endl;
        cout << res[0] << space << res[1] << space << res[2] << endl;
 
     }
    return 0;
}
