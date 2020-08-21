#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int x, n;
    cin >> x >> n;
    map<int, int> ans;
    map<int, int, greater<int>> mp;
    ans[x] = 1;
    mp[0] = x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        auto itr = mp.upper_bound(t);
        int start = itr->first;
        int end = itr->second;
        ans[t - start]++;
        ans[end - t]++;
        ans[end - start]--;
        mp[start] = t;
        mp[t] = end;
        if (ans[end - start] == 0) {
            ans.erase(end - start);
        }
        cout << ans.rbegin()->first << endl;
    }
}