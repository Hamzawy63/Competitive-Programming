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
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
void solve() {
   string s ;
   cin >> s ;
   int n = (int)s.size() ;
   int ans = INT_MAX;
   for(int i=0;i<=9;i++){
       for(int j=0;j<=9;j++){
//           if(i == 3 && j == 3) {
//               int x =0 ;
//           }
           int need = i ;
           int res = 0 ;
           int sz= 0 ;
           for(int k=0;k<n;k++){
               if(s[k] - '0' == need ) {
                   need = (need == i ) ? j : i ;
                   sz ++ ;
               }else
                   res ++ ;
           }
           if((i != j ) && (sz % 2 == 1) ) {
               res ++ ;
           }
           ans = min(res , ans  ) ;
//           if(ans == 0 ) {
//               cerr << i << space << j <<endl;
//           }
       }
   }
   cout << ans << endl;
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}
