#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        auto itr = st.upper_bound(a[i]);
        if (itr == st.end()) {
            ans++;
        } else {
            st.erase(itr);
        }
        st.insert(a[i]);
    }
    cout << ans << endl;
}