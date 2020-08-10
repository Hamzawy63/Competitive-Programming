#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
 ll get_diagonal_at_idx(int d ) {
   return (d-1) * 1ll * (d-1 ) + d ;
}
int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int d = max(y, x);
        ll val = get_diagonal_at_idx(d);
        if (d == y) { // move in y direction
            if (d % 2 == 0) {
                val -= (ll)abs(x - d);
            } else {
                val += (ll)abs(x - d);
            }
        } else if (d == x) {// move in x direction
            if (d % 2 == 0) {
                val += (ll)abs(y - d);
            } else {
                val -= (ll)abs(y - d);
            }
        }
        cout << val << endl;
    }
}
