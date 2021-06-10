#include <bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long
 
 
const int mxN = 103;
int query = 1;
 
void solve() {
    int n ;
    cin >> n ;
    vector<ll> a(3) ;
    vector<int> b(n) ;
    for(int i=0;i<n;i++){
        cin >> b[i] ;b[i]%=3 ;
        a[b[i] ]++ ;
    }
    int part = n/3 ;
    int ans = 0 ;
    while(a[0] < part && a[2] > part) {
        a[0]++;
        a[2]-- ;
        ans ++ ;
    }
 
    while(a[0] < part && a[1] > part) {
        a[0]++;
        a[1]-- ;
        ans +=2 ;
    }
    while(a[1] < part && a[0] > part ) {
        a[1]++ ;
        a[0]-- ;
        ans += 1 ;
    }
    while(a[1] < part && a[2] > part ) {
        a[1]++ ;
        a[2]-- ;
        ans += 2 ;
    }
 
    while(a[2] < part && a[1] > part ) {
        a[2] ++ ;
        a[1] -- ;
        ans +=1 ;
    }
    while(a[2] < part && a[0] > part ) {
        a[2] ++ ;
        a[0]--  ;
        ans += 2 ;
    }
    assert(a[0] == part && a[1] == part && (a[2] == part)) ;
    cout << ans << endl;
//    sort(a.begin() , a.end()) ;
 
 
   
}
 
int main() {
//    freopen("in" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    IO;
    int q = 1;
    if (query) cin >> q;
    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
}
