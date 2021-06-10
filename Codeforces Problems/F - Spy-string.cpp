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
    int n, m;
    cin >> n >> m;
    vector<string> a;
    string res;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (i == 0) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 26; k++) {
                    char chr = s[j];
                    s[j] = (char) ('a' + k);
                    // cout << s << endl;
                    a.push_back(s);
                    s[j] = chr;
                }
            }
        }
        bool ok = false;
        for (int j = 0; j < (int) a.size();) {
            int diff = 0;
            for (int k = 0; k < m; k++) {
                diff += !(s[k] == a[j][k]);
            }
            if (diff < 2) {
                ok = true;
                j++;
            } else {
                a.erase(a.begin() + j);
            }
        }
 
        if (!ok) {
            res = "-1";
        }
    }
    if (res.size() == 0)
        cout << a[0] << endl;
    else
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
