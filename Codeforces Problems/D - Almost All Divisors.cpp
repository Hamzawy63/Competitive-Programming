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
    int q;
    cin >> q;
    while (q--) {
      int n ;
      cin >> n ;
      ll a[n+1] ;
      for(int i = 0 ; i < n ; i++) cin >> a[i] ;
      sort(a , a+n  ) ;
      int l = 0 , r = n -1 ;
      ll res = (ll)a[0] * a[n-1] ;
      while(l<=r) {
          if(a[l] * a[r] != res ) {
              res = -1 ;
              break ;
          }
          l++  ; r-- ;
 
      }
      if(res != -1 ) {
         int div = 0 ;
         for(ll i =  2 ; i * i <= res ; i++)  { 
             if(res %i == 0) div += 2 ; 
             if(i * i == res ) div-=1 ; 
         }
         if(div != n ) res = -1  ; 
      }
      cout << res << endl;
    }
 
 
    return 0;
}
