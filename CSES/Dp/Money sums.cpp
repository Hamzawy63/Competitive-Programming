#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
const int maxN = 5e2 + 3;
const int inf = 1e7;

int main() {
    int n;
    cin >> n;
    vector<int> dp(1e6 + 3);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> res;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = (int) 1e6; j > 0; j--) {
            if (j - a[i] > -1 && !dp[j] && dp[j - a[i]] == 1) {
                dp[j] = 1;
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << (int) res.size() << endl;
    for (auto v : res) {
        cout << v << space;
    }
    cout << endl;

    return 0;
}