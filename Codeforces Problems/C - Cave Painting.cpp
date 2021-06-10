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
#define ACCURATE cout << fixed << setprecision(12)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    IO;
   ll n , k ;
   cin >> n >> k ;
   if(k > 53) cout << "No" ;
   else {
       ll lcm = 1 ;
       for(ll i= 1 ; i <= k  ; i++) lcm = lcm* i / __gcd(lcm , i) ;
       if((n+1) % lcm == 0 ) cout<< "Yes" ;else cout << "No" ;
 
 
 
   }
    return 0;
}
