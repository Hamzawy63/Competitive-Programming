#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    int ans = 0;
    sort(a.begin(), a.end());
    while (l < r) {
        if (a[r] + a[l] <= x) {
            ans++;
            r--;
            l++;
        } else {
            ans++;
            r--;
        }
    }
    int sum = 0;
    for (int i = l; i <= r;) {
        if (sum == 0) {
            sum += a[i];
            ans++;
            i++;
        } else if (sum + a[i] <= x) {
            sum += a[i];
            i++;
        } else {
            sum = 0;
        }
    }
    cout << ans << endl;
}