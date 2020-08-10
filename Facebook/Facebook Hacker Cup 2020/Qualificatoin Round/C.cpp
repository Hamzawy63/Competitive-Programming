#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
void solve() {
   int n ;
   cin >> n ;
   vector<pi> a ;
   map<ll , ll > mpl , mpr ;
   for(int i=0;i<n;i++){
       int x , h ;
       cin >> x >> h ;
       mpl[x] = 0 ;
       mpl[x - h ] = 0 ;
       mpr[x] = 0 ;
       mpr[x+h] = 0 ;
       a.pb({x,h}) ;
   }
   sort(a.begin() , a.end())  ;
    ll ans = -1 ;

    for(int i=0;i<n;i++){
       int x = a[i].ff ;
       int h = a[i].ss ;
       ll res  = max(mpr[x+h] , mpr[x] + h );
       mpr[x+h] = res ;
       ans = max(res , ans ) ;
   }
   for(int i=n-1;i>=0;i--){
       int x = a[i].ff ;
       int h = a[i].ss ;
       ll res  = max(mpl[x-h] , mpl[x] + h);
       mpl[x-h] = res ;
       ans = max(ans , res ) ;

   }
//   for(auto p : mpr) cerr << p.ff << " - > " <<p.ss << endl;
//   cerr << "==============" << endl;
//   for(auto p : mpl ) cerr << p.ff << " -> " << p.ss << endl;

   for(auto p : mpr) {
       if(mpl.count(p.ff))
       ans = max(ans , p.ss + mpl[p.ff]) ;
   }
    cout << ans << endl ;
}

//#define _DEBUG

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
      cin >> q;
    for (int i = 1; i <= q; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
