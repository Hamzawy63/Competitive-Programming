#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mid = a[n / 2];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - mid);
    }
    cout << ans << endl;
}