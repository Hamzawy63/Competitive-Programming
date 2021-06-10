#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define ff first
#define ss second
#define PI atan(1)*4
 
 
void solve() {
 int n ; 
 cin >> n  ; 
 vi a(n) , b(n) ; 
 int ones =  0 , zeros = 0 ; 
 for(int i=0;i<n;i++) cin >> a[i] ; 
 for(int j=0;j<n;j++) {
  cin >> b[j] ;
  if(b[j] == 1 ) ones ++ ; 
  else zeros ++  ;
 }
  
 bool ok = true ; 
 if(zeros * ones == 0 ) {
  for(int i=0;i<n-1;i++ ) if(a[i] > a[i+1]) ok = false ; 
 }  
 if(ok ) cout << "YES" << endl; 
 else cout << "NO" << endl; 
    
   
}
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
