#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second

int main() {
    int n;
    cin >> n;
    stack<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        while (!st.empty() && st.top().ff >= t) {
            st.pop();
        }
        if (st.empty()) {
            cout << 0 << space;
        } else {
            cout << st.top().ss << space ;
        }
        st.push({t, i + 1});
    }
}