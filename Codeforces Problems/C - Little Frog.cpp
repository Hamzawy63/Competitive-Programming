#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <unordered_set>
#include <map>
#include <set>
#include <time.h>
#include <deque>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
 
void solve() {
   int n ;
   cin >> n ;
   int l = 1 , r = n ;
   bool nxt = 0 ;
   while(l <= r ) {
       if(!nxt) {
           cout << l << space ;
           nxt = !nxt ;
           l++ ;
       }else {
           cout << r << space;
           nxt =!nxt ;
           r-- ;
       }
   }
 
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
    solve();
}
