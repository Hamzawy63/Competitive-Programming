#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int x, n;
    cin >> x >> n;
    map<int, int> mp;
    mp[x] = 1;
    set<int> st;
    st.insert(0);
    st.insert(x);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        auto itr = st.lower_bound(t);
        int r = *itr;
        itr--;
        int l = *itr;
        mp[r - t]++;
        mp[t - l]++;
        mp[r - l]--;
        st.insert(t);
        if (!mp[r - l]) mp.erase(r - l);

        cout << mp.rbegin()->first << endl;


    }
}