#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
int main() {
    ll n;
    int k;
    cin >> n >> k;
    auto range = [&](int from, int to) {
        ll ans = to * 1LL * (to + 1) / 2;
        ans -= from * 1LL * (from - 1) / 2;
        return ans;
    };
    if (n <= k) {
        if (n == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }
 
    ll need = n - 1;
    int lb = 1, rb = k - 1;
    int ans = -1;
    while (lb <= rb) {
        int mb = (lb + rb) / 2;
        if (range(mb, k - 1) <= need) {
            ans = mb;
            rb = mb - 1;
        } else {
            lb = mb + 1;
        }
    }
    if (range(ans, k - 1) < need && ans == 1) {
        cout << -1 << endl;
    } else {
        cout << (k - 1 - ans + 1) + (range(ans, k - 1) != need);
    }
 
 
}
