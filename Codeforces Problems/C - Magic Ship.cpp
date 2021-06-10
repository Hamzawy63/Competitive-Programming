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
typedef  long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
void solve() {
    ull x0, y0, x1, y1;
    cin >> x0 >> y0;
    cin >> x1 >> y1;
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto can = [&](ull mid) {
        ull repeated = mid / n;
        ull mod = mid % n;
        ull xn = x0, yn = y0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') {
                yn += repeated;
                if (i < mod) yn++;
            } else if (s[i] == 'D') {
                yn -= repeated;
                if (i < mod) yn--;
            } else if (s[i] == 'R') {
                xn += repeated;
                if (i < mod) xn++;
            } else if (s[i] == 'L') {
                xn -= repeated;
                if (i < mod) xn--;
            }
        }
        return abs((ll)xn - (ll)x1) + abs((ll)yn - (ll)y1) <= mid;
 
    };
    bool ok = false;
    ull ans;
    ull l = 0, r = LONG_LONG_MAX;
 
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (can(mid)) {
            ok = true;
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    if (!ok) {
        cout << -1 << endl;
    } else
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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
