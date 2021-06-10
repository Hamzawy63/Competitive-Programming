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
 
void solve() {
    int n, k;
    cin >> n >> k;
    int ans;
    if (k > n ) {
        ans = k - n ;
    } else {
        if (n % 2 != k % 2) ans = 1;
        else ans = 0 ;
    }
    cout << min(abs(n - k), ans) << endl;
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
