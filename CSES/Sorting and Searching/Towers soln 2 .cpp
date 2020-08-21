#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n;
    cin >> n;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int p = upper_bound(dp.begin(), dp.end(), t) - dp.begin();
        if (p < (int) dp.size()) {
            dp[p] = t;
        } else {
            dp.push_back(t);
        }
    }
    cout << (int) dp.size() << endl;
}