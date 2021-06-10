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
    int n ;
    cin >> n ;
    vi a(n) ;
    for(int i=0;i<n;i++){ cin >> a[i] ; }
    int l = 0 , r = n-1 ;
    while(l < n-1 && a[l+1] > a[l]) l++ ;
    while(r > 0 && a[r] < a[r-1]) r-- ;
    bool ok = true ;
    for(int i=l;i<r;i++){
        if(a[i] != a[i+1]) ok =false ;
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
 
 
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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
