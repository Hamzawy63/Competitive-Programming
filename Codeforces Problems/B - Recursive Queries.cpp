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
 
const ll MAX = (ll) 1e18;
int maxN = 1e6;
vector<int> cnt[12];
 
void solve() {
    vector<int> g(maxN + 3);
    for (int i = 0; i <= maxN; i++) {
        if (i < 10) g[i] = i;
        else {
            int f = 1;
            int cur = i;
            while (cur > 0) {
                if (cur % 10 != 0) {
                    f *= cur % 10;
                }
                cur /= 10;
            }
            g[i] = g[f];
        }
        if (g[i] < 10) cnt[g[i]].push_back(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int L, R, x;
        cin >> L >> R >> x;
        int st = lower_bound(cnt[x].begin(), cnt[x].end(), L) - cnt[x].begin();
        int en = upper_bound(cnt[x].begin(), cnt[x].end(), R) - cnt[x].begin();
        if (st == (int) cnt[x].size() || cnt[x][st] > R) {
            cout << 0 << endl;
        } else
            cout << en - st << endl;
    }
 
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
    //  freopen("output.txt", "w", stdout);
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
