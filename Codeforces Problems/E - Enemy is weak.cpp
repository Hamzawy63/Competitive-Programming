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
const int maxN = 1e6 + 3;
 
int n;
vector<int> fenf(maxN), fenr(maxN);
 
void add(int l, int d, vector<int> &fen) {
    while (l < n) {
        fen[l] += d;
        l = (l | (l + 1));
    }
}
 
int sum(int r, vector<int> &fen) {
    int ans = 0;
    while (r >= 0) {
        ans += fen[r];
        r = (r & (r + 1)) - 1;
    }
    return ans;
}
 
int range_sum(int l, int r, vector<int> &fen) { // (l , r]
    int ans = sum(r, fen) - sum(l , fen);
   // if (l > 0) ans -= sum(l - 1, fen);
    return ans;
}
 
void solve() {
    cin >> n;
    vector<int> a(n), h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        a[i] = h[i];
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin();
    }
    for (int i = 0; i < n; i++) {
        add(a[i], 1, fenr);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        add(a[i], -1, fenr);
        ll left = range_sum(a[i], n - 1, fenf);
        ll right = sum(a[i] - 1, fenr);
    //    cerr << "Left = " << left << space << " Right = " << right << endl ;
        ans += left * right;
        add(a[i], 1, fenf);
    }
    cout << ans <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
