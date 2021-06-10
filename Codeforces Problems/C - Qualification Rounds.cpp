#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            if (t)
                res |= (1 << j);
        }
        if (!st.count(res)) {
            st.insert(res);
            a.push_back(res);
        }
    }
    int sz = (int) a.size();
    for (int i = 1; i < (1 << sz); i++) {
        vector<int> know(k);
 
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) {
                int cur = a[j];
                for (int l = 0; l < k; l++) {
                    if (cur & (1 << l)) {
                        know[l]++;
                    }
                }
            }
 
        }
        bool ok = true;
        for (auto v : know) {
            if (v > __builtin_popcount(i) / 2) ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
