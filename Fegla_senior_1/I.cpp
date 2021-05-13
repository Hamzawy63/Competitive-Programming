#include <bits/stdc++.h>

using namespace std;

bool debug = false ;

int main() {
#ifdef  _SHIT
    debug = true ;
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long int ans = 0;
    // subsegemnts where i is the maximum last
    stack<pair<int, long long int >> st;
    st.push({-1, INT_MAX});
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().second <= a[i]) {
            st.pop();
        }
        int his = st.top().first;
        L[i] = his + 1;
//        ans += a[i] * (i - his);
        st.push({i, a[i]});
    }
    while (!st.empty()) st.pop();
    st.push({n, INT_MAX});
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().second < a[i]) {
            st.pop();
        }
        int his = st.top().first;
//        ans += a[i] * (his - i);
        R[i] = his - 1;
        st.push({i, a[i]});

    }
    for (int i = 0; i < n; ++i) {
        ans += (i - L[i] + 1) * 1LL * (R[i] - i + 1) * a[i];
    }
    if (debug) {
        for (int i = 0; i < n; i++) {
            cerr << L[i] << ' ';
        }
        cerr << endl;
        for (int i = 0; i < n; i++) {
            cerr << R[i] << ' ';
        }
        cerr << endl;
    }
    while (!st.empty()) st.pop();
    st.push({-1, INT_MIN});
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().second > a[i]) {
            st.pop();
        }
        int his = st.top().first;
//        ans -= a[i] * (i - his);
        L[i] = his + 1;
        st.push({i, a[i]});

    }
    while (!st.empty()) st.pop();
    st.push({n, INT_MIN});
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().second >= a[i]) {
            st.pop();
        }
        int his = st.top().first;
        R[i] = his - 1;
//        ans -= a[i] * (his - i);
        st.push({i, a[i]});
    }
    for (int i = 0; i < n; i++) {
        ans -= (i + 1 - L[i]) * 1LL * (R[i] - i + 1) * a[i];
    }

    if (debug) {
        for (int i = 0; i < n; i++) {
            cerr << L[i] << ' ';
        }
        cerr << endl;
        for (int i = 0; i < n; i++) {
            cerr << R[i] << ' ';
        }
        cerr << endl;
    }
    cout << ans << endl;
    return 0;
}