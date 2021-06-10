#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
typedef long long int ll;
using namespace std;
 
#define vi vector<int>
const int Mod = 1000000007;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);
    vi pre(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            pre[i] = 1;
        } else {
            pre[i] = 0;
        }
    }
    for (int i = 1; i < n; i++) pre[i] += pre[i - 1];
    int l = 0, ans = 0;
    for (int i = 0; i < n - k + 1; i++) {
        int res = pre[i + k - 2] - pre[i];
        if (res > ans) {
            ans = res;
            l = i;
        }
    }
    cout << ans + 1 << " " << l + 1 << endl;
 
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
 
//    solve();
 
    return 0;
}
