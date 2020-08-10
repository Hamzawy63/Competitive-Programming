#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main() {
  int n;
  cin >> n ;
  int last = 0 ;
  ll ans= 0;
  for(int i=0;i<n;i++) {
      int t;
      cin >> t ;
      if(t < last ) ans += (ll)last - (ll)t ;
      else last = t ;
  }
  cout << ans << endl;
}
