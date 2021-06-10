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
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
 
 
void solve() {
    int n , m ;
    cin >> n >> m ;
    vector<int > a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin() , a.end() , greater<>() ) ;
    int res = 0 ;
    int sum = 0 ;
    for(int i=0;i<n;i++) {
        sum += a[i] ;
        res++ ;
        if(sum >= m ) break ;
    }
    cout << res << endl;
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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
