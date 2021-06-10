#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
const double eps = 0.0000001;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    int l = INT_MAX;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = min(a[i], l);
        if (a[i] == k) ok = true;
    }
    if (!ok) {
        cout << "no" << endl;
        return;
    }
    if(l == k ) {
        cout << "yes" <<endl;return ;
    }
    ok = false;
    for (int i = 0; !ok && (i < n - 1) ; i++) {
        if (a[i] >= k && a[i + 1] >= k) ok = true;
    }
    for (int i = 0; !ok && (i < n - 2) ; i++) {
        vi b = {a[i], a[i + 1], a[i + 2]};
        sort(b.begin(), b.end());
        if (b[1] >= k) ok = true;
    }
 
    if (ok) cout << "yes" << endl; else cout << "no" << endl;
 
}
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int q = 1;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}
