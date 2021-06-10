#include <bits/stdc++.h>
 
#define ll long long int
using namespace std;
#define space " "
#define vii vector<vector<int>>
#define vi vector<int>
#define EPS 0.000000001
#define ld long  double
 
void solve() {
    ll aa, bb;
    cin >> aa >> bb;
    ll gg = __gcd(aa, bb);
    vi a;
    for (ll i = 1; i * i <= gg; i++) {
        if (gg % i == 0) {
            a.push_back(i);
            if (i * i != gg) {
                a.push_back(gg / i);
            }
        }
    }
    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        auto itr = upper_bound(a.begin(), a.end(), y);
        if (itr == a.begin()) {
            cout << -1 << endl;
            continue;
        }
        itr--;
        int val = *itr;
        if (val >= x) {
            cout << val << endl;
        } else {
            cout << -1 << endl;
        }
    }
 
}
 
int main() {
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
 
}
