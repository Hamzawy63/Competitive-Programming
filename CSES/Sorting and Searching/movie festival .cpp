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
    vector<pi > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ss >> a[i].ff;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int last = -1;
    for (auto p : a) {
        if (p.ss >= last) {
            ans++;
            last = p.ff;
        }
    }
    cout << ans << endl;
}