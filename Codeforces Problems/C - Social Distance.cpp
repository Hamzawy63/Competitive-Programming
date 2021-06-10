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
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define ff first
#define ss second
void solve() {
 int n , k ;
 cin >> n >> k;
 string s ;
 cin >> s ;
 const int INF = 10000000 ;
 vi post(n) ;
 post[n-1] = s[n-1] == '1' ? n-1 : INF ;
 for(int i = n-2 ; i >= 0 ; i--){
     if(s[i] == '1') post[i] = i ;
     else post[i] = post[i+1] ;
 }
 int last = -INF ;
 int res =0;
 for(int i=0;i<n;i++){
     if(s[i] == '0') {
         if(abs(i - last) > k && abs(post[i] - i ) > k  ){
             s[i] = '1' ;
             last = i ;
             res ++ ;
         }
     }else
         last = i ;
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
