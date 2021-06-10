#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
const double eps = 0.0000001;
 
void solve() {
   int n ;
   cin >> n ;
   vi a(n+2);
   for(int i =0;i<n;i++) cin >> a[i+1] ;
   vi dp(n+2,1) ;
   int ans = 1 ;
   for(int i =1 ; i <=n ; i++ ){
       for(int j = 2 * i ; j <= n ;j+=i) {
           if(a[j] > a[i]) {
               dp[j] = max(dp[i] + 1 , dp[j]) ;
               ans = max(ans , dp[j]) ;
           }
       }
   }
   cout << ans <<endl; 
 
}
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int q = 1;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}
