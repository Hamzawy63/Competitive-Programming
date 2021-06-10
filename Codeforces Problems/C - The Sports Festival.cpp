#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
ll dp[2002][2002];
 
void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
}
 
ll solve(vector<ll> &a, vector<ll> &b, int i, int j) {
    assert(i <= j);
    assert(i >= 0);
    int n = (int) a.size();
    assert(j < n);
    if (i == 0 && j == n - 1) return 0;
    ll ans = LLONG_MAX;
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (j + 1 < n) {
        ans = (a[j + 1] - a[i]) * b[j + 1];
        ans += solve(a, b, i, j + 1);
    }
    if (i - 1 >= 0) {
        ll res = (a[j] - a[i - 1]) * b[i - 1];
        res += solve(a, b, i - 1, j);
        ans = min(ans, res);
    }
    return dp[i][j] = ans;
 
}
 
 
int main() {
    int n;
    cin >> n;
    map<ll, int> mp;
    vector<ll> all;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t] += 1;
        all.push_back(t);
    }
    vector<ll> a;
    vector<ll> b;
    ll best = -1;
    ll freq = -1;
    for (auto p : mp) {
        a.push_back(p.first);
        b.push_back(p.second);
        if (p.second > freq) {
            best = p.first;
            freq = p.second;
        }
 
    }
    n = (int) a.size();
    ll ans = LONG_LONG_MAX;
    init(n) ;
    for (int i = 0; i < n; i++) {
        ans = min(solve(a, b, i, i), ans);
 
    }
    cout << ans << endl;
    return 0;
}
