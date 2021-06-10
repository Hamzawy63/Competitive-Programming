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
    int n;
    cin >> n;
    vi a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i] * (i % 2 == 0);
    }
    ll max_so_far = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && i % 2 == 0) {
            max_so_far += a[i + 1] - a[i];
            max_so_far = max(max_so_far, 0LL);
            res = max(res, max_so_far);
        }
    }
    ll min_so_far = 0, res2 =LONG_LONG_MAX;
    for (int i = 2; i < n; i+=2) {
     min_so_far += a[i] - a[i-1] ;
     min_so_far = min(0LL, min_so_far) ;
     res2 = min(res2 , min_so_far) ;
    }
    //cerr << res << space << res2 << endl;
    cout << s + max(res, -1 * res2) << endl;
 
 
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
