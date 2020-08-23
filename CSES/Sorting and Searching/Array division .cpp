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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll l = *max_element(a.begin(), a.end()), r = sum;
    ll ans = 0;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        int cnt = 1;
        ll sum = 0;
        for (int i = 0; i < n;) {
            if (a[i] + sum > mid) {
                cnt++;
                sum = 0;
            } else {
                sum += a[i];
                i++;
            }
        }
        if (cnt <= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
