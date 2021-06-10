#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <sstream>
#include <random>
#include <iterator>
 
typedef long long int ll;
using namespace std;
#define vl vector<ll>
#define vi vector<int>
 
 
void solve() {
   int q ;
   cin >> q ;
   while(q-- ) {
       int n ;
       cin >> n ;
       ll ans = 1 << n  ;
       for(int i = 1 ; i < n/2 ; i++  ) ans += 1<< i ;
       for(int j = n/2 ; j < n ;j++ ) ans -= 1 << j ;
       cout << ans << endl; 
   }
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        // cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();
 
    return 0;
}
