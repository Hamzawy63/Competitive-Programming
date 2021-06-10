#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
typedef long long int ll;
using namespace std;
#define vl vector<ll>
#define vi vector<int>
#define ff first
#define ss second
 
void solve() {
    int n;
    cin >> n;
    vl m(n);
    for (int i = 0; i < n; i++) cin >> m[i];
    vl left(n), right(n);
    stack<pair<int, int >> st;
    st.push({m[0], 0});
    left[0] = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i] >= m[i - 1]) left[i] = left[i - 1] + m[i];
        else {
            int j = -1; // magic index :)
            while (!st.empty() && st.top().ff > m[i])
                st.pop();
            if (!st.empty())
                j = st.top().ss;
            if (j == -1)
                left[i] = (i + 1) * m[i];
            else
                left[i] = left[j] + (i - j ) * m[i];
        }
        st.push({m[i], i});
    }
    reverse(m.begin(), m.end());
    while (!st.empty()) st.pop();
 
    st.push({m[0], 0});
    right[0] = m[0];
    for (int i = 1; i < n; i++) {
        if (m[i] >= m[i - 1]) right[i] = right[i - 1] + m[i];
        else {
            int j = -1; // magic index :)
            while (!st.empty() && st.top().ff > m[i])
                st.pop();
            if (!st.empty())
                j = st.top().ss;
            if (j == -1)
                right[i] = (i + 1) * m[i];
            else
                right[i] = right[j] + (i - j ) * m[i];
        }
        st.push({m[i], i});
    }
 
 
    reverse(right.begin(), right.end());
    reverse(m.begin(), m.end());
 
    vl res(n);
    ll ans = 0;
    ll idx = -1;
    for (int i = 0; i < n; i++) {
        if (left[i] + right[i] - m[i] > ans) {
            ans = left[i] + right[i] - m[i];
            idx = i;
        }
    }
    res[idx] = m[idx];
    for (int i = idx + 1; i < n; i++) {
        res[i] = min(res[i - 1], m[i]);
    }
    for (int i = idx - 1; i >= 0; i--) {
        res[i] = min(res[i + 1], m[i]);
    }
  //  cout << ans << endl;
    for (int i = 0; i < n; i++) cout << res[i] << " ";
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        // cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();
 
    return 0;
}
