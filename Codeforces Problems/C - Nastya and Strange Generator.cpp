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
    int n;
    cin >> n;
    vi p(n);
    vi idx(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        idx[p[i]] = i;
    }
    int nxt = 0;
    int end = n;
    int nxtend = n;
    bool ok = true;
    int cnt = 1;
    while (ok && cnt < n) {
        nxtend = idx[nxt];
        for (int i = idx[nxt]; i < end; i++) {
            nxt++;
            cnt++;
            if ((i < end - 1) && p[i + 1] - p[i] != 1) {
                ok = false;
            }
            if (i == end - 1)
                end = nxtend;
        }
        end = nxtend;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
