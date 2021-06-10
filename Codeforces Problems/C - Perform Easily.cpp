#include <bits/stdc++.h>
 
using namespace std;
#define space " "
using ll =  long long int;
 
void solve() {
    vector<int> a(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> all;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            all.push_back({b[i] - a[j], i});
        }
    }
    sort(all.begin(), all.end());
    int ans = INT_MAX;
    int r = 5;
    int sz = (int) all.size();
    map<int, int> mp;
    for(int i=0;i<6;i++){
        mp[all[i].second]++ ;
    }
    for (int i = 0; i < sz; i++) {
        bool ok = false;
        while (r < sz && !ok) {
            ok = (int) mp.size() == n;
            if (!ok) {
                r++;
                if (r < sz)
                    mp[all[r].second]++;
            }
        }
        if (!ok) {
            break;
        } else {
            ans = min(ans, all[r].first - all[i].first);
        }
        mp[all[i].second]--;
        if (mp[all[i].second] == 0) {
            mp.erase(all[i].second);
        }
    }
    cout << ans << endl;
 
 
}
 
#define LOCAL
 
int main() {
//    freopen("gift1.in", "r", stdin);
//    freopen("gift1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }
}
