#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int nn, b, p;
 
int go(int n) {
    if (n == 1) return 0;
    int exp = log2(n);
    int half = (1 << exp) / 2;
    int carry = n - (1 << exp);
    return ((1 << exp) * b + half + go(half  + carry));
}
 
void solve() {
    cin >> nn >> b >> p;
    cout << go(nn) << " " << p * nn << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO5
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
