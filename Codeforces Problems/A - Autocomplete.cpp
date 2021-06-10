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
  string s ;
  int n ;
  cin >>s >> n ;
  vector<string > a(n);
  for(int i = 0 ; i < n ;i++ ) cin >> a[i] ;
  sort(a.begin() , a.end() ) ;
  int idx = lower_bound(a.begin() , a.end() , s ) - a.begin()  ;
  if(idx == n || a[idx].substr(0 , (int)s.size()) != s ) cout << s << endl;
  else {
      cout << a[idx] << endl;
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
