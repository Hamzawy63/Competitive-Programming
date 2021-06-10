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
  string s;
  cin >> s ;
  vector<vector<ll>> dp(26 , vector<ll>(26,0)) ;
  vi f(26,0) ;
  int n = (int)s.size() ;
  ll ans = 0 ;
  for(int i=0;i<n;i++){
      for(int j=0;j<26;j++){
          dp[j][s[i] - 'a'] += f[j] ;
          ans = max(ans , dp[j][s[i] - 'a'] ) ;
      }
      f[s[i] - 'a']++ ;
  }
  for(int i=0;i<26;i++ ) ans = max(ans , 1ll * f[i]) ;
  cout << ans << endl;
 
}
 
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
 
 
//       ababkamts
//    t-> bbk
//    u->aaa
