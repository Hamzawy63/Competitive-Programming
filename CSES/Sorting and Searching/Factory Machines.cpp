#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll lb = 0, rb = 1000000000000000000;
    ll ans = -1;
    while (lb <= rb) {
        ll mb = lb + (rb - lb) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (ll)mb/a[i] ;
            if(cnt >= x ) break;
        }
        if (cnt >= x) {
            ans = mb;
            rb = mb - 1;
        } else lb = mb + 1;
    }
    cout << ans << endl;
}