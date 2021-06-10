#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
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
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vi a(n), pre(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) pre[i] = a[i]; else pre[i] = a[i] + pre[i - 1];
        if (i <= k) ans += a[i];
    }
    for (int i = 1; i < k; i++) {
        int res = pre[i];
        int steps = k - i;
        int zz = 0;
        int last =-1;
        for (int j = 0; (zz < z) && (steps > 0); j++, steps--) {
            if (j % 2 == 0) {
                res += a[i - 1];
                zz++;
                last = i-1 ;
            }
            else {
                res += a[i];
            }
        }
        if((steps > 0) && (last != i-1 )) {
            res += (pre[i+steps] - pre[i]) ;
        }else
            res += pre[i+steps-1] - pre[i-1] ;
      //  cerr << res << space ;
        ans = max(res , ans ) ;
    }
    cout << ans << endl;
}
 
//#define _DEBUG
 
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
