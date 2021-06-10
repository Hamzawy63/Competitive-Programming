#include <bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long
 
 
const int mxN = 103;
int query = 1;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int >> all;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto p : mp) {
        all.push_back({p.second, p.first});
 
    }
    sort(all.begin(), all.end());
    ll prefix = 0;
    vector<ll> pre;
    for (int i = 0; i < (int) all.size(); i++) {
        prefix += all[i].first;
        pre.push_back(prefix);
    }
    ll minimum_cost = LLONG_MAX;
    int sz = (int) all.size();
    int biggest = all.back().first;
//    cerr << biggest << endl;
//    for (int i = 0; i < sz; i++) {
//        cerr << all[i].first << space ;
//    }
//    cerr << endl;
    for (int i = 0; i <= biggest; i++) {
        // remove all numbers smallest that i occurs
        int lb = 0, rb = (int) all.size();
        int first = -1;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            if (all[mb].first >= i) {
                first = mb;
                rb = mb - 1;
            } else {
                lb = mb + 1;
            }
        }
        ll cost = pre[sz - 1];
        if (first > 0 ) {
            cost -= pre[first - 1];
            cost -= (sz - 1 - first + 1) * i;
            cost += pre[first - 1];
        } else {
            cost -= sz * i;
        }
     //   cerr << cost << endl;
        if (cost < minimum_cost) {
 
            minimum_cost = cost;
 
        }
    }
    cout << minimum_cost << endl;
}
 
int main() {
//    freopen("in" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    IO;
    int q = 1;
    if (query) cin >> q;
    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
}
