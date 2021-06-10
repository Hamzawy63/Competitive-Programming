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
const double eps = 0.0000001;
const int maxN = 10000000;
int s[maxN + 7];
int f[maxN + 6];
int p[maxN + 6];
 
void solve() {
    for (int i = 0; i <= maxN; i++) {
        s[i] = 1;
        f[i] = 0;
        p[i] = 0;
    }
    s[0] = 0;
    s[1] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        f[t]++;
    }
    for (ll i = 2; i <= maxN; i++) {
        if (s[i] == 1) {
            p[i] += f[i] ;
            for (ll j = 2 * i; j <= maxN; j += i) {
                s[j] = 0;
                if (f[j] != 0) p[i] += f[j];
            }
        }
        p[i] += p[i-1] ;
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = min(l, maxN);
        r = min(r, maxN);
        cout << p[r] - p[l - 1] << endl;
    }
 
 
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
    // cin >> q ;
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}
