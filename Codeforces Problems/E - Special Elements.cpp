#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <unordered_set>
#include <map>
#include <set>
#include <deque>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
 
int freq[8001] ;
int a[8002] ;
void solve() {
   int n ;
   cin >> n ;
   for(int i = 0 ; i<=8000 ; i++ ) freq[i] = 0 ;
   for(int i =0 ; i < n ;i++ ){
       cin >> a[i] ;
       freq[a[i]] += 1 ;
       if(i > 0 ) a[i] += a[i-1] ;
   }
   int res = 0 ;
   for(int i = 0 ; i< n ;i++ ){
       for(int j = i + 1 ; j < n ;j++ ) {
           if(j - i + 1 > 1 ) {
               int sum = a[j] ;
               if(i > 0 ) sum -= a[i-1] ;
               if(sum <= 8000 && freq[sum] > 0 ) {
                   res += freq[sum] ;
                   freq[sum] = 0 ;
               }
           }
       }
   }
    cout << res <<endl ;
}
 
//cout << "Case #" << i << ": ";
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q ;
    cin >> q ;
    while(q--  )
        solve();
    return 0;
}
