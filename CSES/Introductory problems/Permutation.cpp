#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main() {
  int n;
  cin >> n ;
  if(n==2 || n ==3  ) cout << "NO SOLUTION" << endl;
  else if(n==1 ) cout << 1 << endl;
  else {
      vector<int> ans = {1,n};
      for(int i=2;i<n;i+=2){
          ans.push_back(i) ;
      }
      reverse(ans.begin(),ans.end()) ;
      for(int i=3;i<n;i+=2){
          ans.push_back(i) ;
      }
      for(auto v : ans) cout << v << " " ;
      cout << endl ;
  }
}
