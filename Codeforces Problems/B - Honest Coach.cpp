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
    int n;
    cin >> n;
    int res = 100000000;
    vi a(n) ;
    for(int i =0;i<n;i++ ) cin >> a[i] ;
    sort(a.begin() , a.end()) ;
    for (int i = 1; i < n; i++){
        res = min(res , abs(a[i]- a[i-1])) ;
    }
    cout << res << endl ;
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
