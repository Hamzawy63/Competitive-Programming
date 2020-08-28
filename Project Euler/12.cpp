#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const vector<int> dy = {0, 0, 1, 0, -1, 1, -1, 1, -1};

void solve() {
    bool ok = false;
    ll cnt = 1;
    while (!ok) {
        ll k = (cnt * (cnt + 1)) / 2;
        cerr << "Working on " << k << endl;
        int div = 0;
        for (ll i = 1; i * 1ll * i <= k; i++) {
            if (k % i == 0) {
                div += 2;
            }
            if (i * 1ll * i == k) {
                div -= 1;
            }
        }
        if (div >= 500) {
            cout << k << endl;
            ok = true;
        }
        cnt++ ;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
    //  freopen("output.txt", "w", stdout);
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}