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
const int maxN = 4e5 + 4 ; 
int n;
vector<int> fen(maxN);
 
void add(int l, int d) {
    while (l < 2 * n) {
        fen[l] += d;
        l = (l | (l + 1));
    }
}
 
int sum(int r) {
    int ans = 0;
    while (r >= 0) {
        ans += fen[r];
        r = (r & (r + 1)) - 1;
    }
    return ans;
}
void solve() {
    cin >> n;
    vector<int> all;
    vector<pair<pair<int, int>, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff.ff >> a[i].ff.ss;
        all.push_back(a[i].ff.ff);
        all.push_back(a[i].ff.ss);
        a[i].ss = i;
 
    }
    sort(all.begin(), all.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        a[i].ff.ff = lower_bound(all.begin(), all.end(), a[i].ff.ff) - all.begin();
        a[i].ff.ss = lower_bound(all.begin(), all.end(), a[i].ff.ss) - all.begin();
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        add(a[i].ff.ss, 1);
    }
    for (int i = 0; i < n; i++) {
        add(a[i].ff.ss, -1);
        res[a[i].ss] = sum(a[i].ff.ss - 1);
    }
    for (auto v : res)cout << v << endl;
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
