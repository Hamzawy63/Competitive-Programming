#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array

int main() {
    int n;
    cin >> n;
    vector<ar<int, 3>> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(), a.end());
    set<ar<int, 2>, greater<ar<int, 2>>> st;
    for (int i = 0; i < n; i++) {
        int start = a[i][0];
        int en = a[i][1];
        int visitor_idx = a[i][2];
        auto itr = st.upper_bound({start});
        if (itr == st.end()) {
            ans[visitor_idx] = (int) st.size();
        } else {
            ans[visitor_idx] = (*itr)[1];
            st.erase(itr);
        }
        st.insert({en, ans[visitor_idx]});
    }

    cout << (int) st.size() << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << space;
    }
}