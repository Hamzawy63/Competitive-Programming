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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    bool ok = true;
    if ((a - b) * n > c + d || (a + b) * n < (c - d)) ok = false;
    if (ok) cout << "Yes";
    else cout << "No";
    cout << endl;
 
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
