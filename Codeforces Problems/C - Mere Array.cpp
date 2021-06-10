#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
 
void check(bool ok) {
    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s.begin(), s.end());
    int least = s[0];
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (s[i] != a[i] && s[i] % least != 0) ok = false;
    }
    check(ok);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
      cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
