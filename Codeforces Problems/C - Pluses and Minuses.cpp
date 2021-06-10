#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
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
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
 
void solve() {
   string s ;
   cin >> s ;
   int n = (int)s.size() ;
   int pre = 0 ;
   int cost = 0 ;
   vi a ;
   ll res =0 ;
   for(int i=0;i<n;i++){
       if(s[i] == '-') pre -- ;
       else pre ++ ;
       cost ++ ;
       if( pre < 0 ) {
           a.push_back(cost) ;
           pre =0;
           cost =0;
       }
   }
   res += cost ;
   int k = (int)a.size() + 1;
   for(int i=0;i<(int)a.size() ;i++){
        res += a[i] *1ll* (k--) ;
   }
   cout << res <<endl;
}
 
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
