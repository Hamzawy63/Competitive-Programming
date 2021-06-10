#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ts = 0;
    int need_t2 = 0;
    bool ok = true;
    vector<int> have(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'M') {
            have[i] += 1;
        }
        if (i + 1 < n) have[i] += have[i + 1];
    }
    int bad = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            if (have[i] - bad > 0) {
                ts += 1;
                bad += 1;
            } else if (need_t2 > 0) {
                need_t2 -= 1;
            } else {
                ok = false;
            }
        } else if (s[i] == 'M') {
            bad -=1 ;
            if (ts > 0) {
                ts -= 1;
                need_t2 += 1;
            } else {
                ok = false;
                break;
            }
        }
    }
    if (ts == 0 && need_t2 == 0) {
 
    } else {
        ok = false;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
