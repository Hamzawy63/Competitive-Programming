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
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ACCURATE ;
   int  n , l , r , x ;
   cin >> n >> l >> r >> x;
   vi a(n) ;
   for(int i  = 0 ; i <  n ; i++) {
       cin >> a[i] ;
   }
   sort(a.begin() , a.end()) ;
   int res = 0 ;
   for(int i = 0; i < (1<<n) ; i++ ){
       vi one ;
       int sum = 0 ;
       for(int j  =0  ; j < n ; j++ ){
           if(i & (1<<j) ){
               sum +=a[j] ;
               one.push_back(a[j]) ;
       }}
     //  for(auto k : one ) cout << k << space ;
     //  cout << endl;
       if(!one.empty() && ((one[(int)one.size() - 1] - one[0]) >=x) && (sum >= l )&& (sum <= r)) res ++  ;
 
   }
   cout << res << endl ;
    return 0;
}
