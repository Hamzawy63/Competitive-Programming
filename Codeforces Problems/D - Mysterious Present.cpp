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
 
struct Envelope {
    int w, h, idx;
 
    bool operator<(const Envelope &o) {
        return make_pair(w, h) < make_pair(o.w, o.h);
    }
};
 
void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    vector<Envelope> a;
    for (int i = 0; i < n; i++) {
        int ww, hh;
        cin >> ww >> hh;
        if (ww > w && hh > h) {
            a.push_back({ww, hh, i + 1});
        }
    }
    int ans = 0;
    int ans_idx = -1;
    int sz = (int) a.size();
    sort(a.begin(), a.end());
    vector<pi > dp(sz);
    for (int i = 0; i < sz; ++i) {
        dp[i] = {1, i};
        for (int j = 0; j < i; j++) {
            if (a[j].w < a[i].w && a[j].h < a[i].h && dp[i].ff < 1 + dp[j].ff) {
                dp[i] = {1 + dp[j].ff, j};
            }
        }
        if (dp[i].ff > ans) {
            ans = dp[i].ff;
            ans_idx = i;
        }
    }
    cout << ans << endl;
    vector<int> rev ;
    while (ans--) {
        rev.push_back(a[ans_idx].idx) ;
        ans_idx = dp[ans_idx].ss;
    }
    reverse(rev.begin() , rev.end()) ;
    for(auto r : rev ) {
        cout << r << space ; 
    }
 
}
 
int main() {
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
