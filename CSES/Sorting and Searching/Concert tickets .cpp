#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    multiset<int, greater<int>> st;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        st.insert(t);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto itr = st.lower_bound(t);
        if (itr == st.end()) {
            cout << -1 << endl;
        } else {
            cout << *itr << endl;
            st.erase(itr);
        }
    }
}