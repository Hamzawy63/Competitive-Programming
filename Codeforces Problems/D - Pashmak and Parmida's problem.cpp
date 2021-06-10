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
const int maxN = 1000000 + 1;
int fen[maxN];
int n;
 
void add(int r, int d) {
    if (r == 0) return;
    while (r <= n) {
        fen[r] += d;
        r += (r & -r);
    }
}
 
int sum(int l) {
    int ans = 0;
    while (l > 0) {
        ans += fen[l];
        l -= (l & -l);
    }
    return ans;
}
 
void solve() {
    cin >> n;
    vector<int> a(n), h(n), cnt1(n, 0), cnt2(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h[i] = a[i];
    }
    sort(h.begin(), h.end());
    h.erase(unique(h.begin(), h.end()), h.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin();
    }
    h.assign(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        cnt2[a[i]]++;
        h[i] = cnt2[a[i]];
        add(cnt2[a[i]], 1);
    }
    ll ans = 0;
//    for(int i=1;i<n;i++){
//       cerr  << sum(i) - sum(i - 1 ) << space ;
//    }
//    cerr << endl;
    for (int i = 0; i < n; i++) {
        cnt1[a[i]]++;
        add(h[i], -1);
        ans += sum(cnt1[a[i]] - 1);
    }
    cout << ans << endl;
 
 
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
