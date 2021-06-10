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
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
 
void solve() {
    int n , x ;
    cin >> n >> x ;
    int e = 0 , o = 0 ;
    for(int i=0;i<n;i++ ){
        int t;
        cin >> t ;
        if(t%2) o++ ; else e++ ;
    }
    bool ok = false ;
    for(int i = 1 ; i <= n ; i+=2){
        if((o >= i) && (x >= i && e >= x-i)) ok = true;
    }
    if(ok ) cout << "Yes" << endl;
    else cout << "No" << endl;
 
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
