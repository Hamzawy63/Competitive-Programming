#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n;
    cin >> n;
    vector<int> vals, in(n), out(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i] >> out[i];
        vals.push_back(in[i]);
        vals.push_back(out[i]);
    }
    sort(vals.begin(), vals.end());
    // Coordinates compression :)
    for (int i = 0; i < n; i++) {
        in[i] = lower_bound(vals.begin(), vals.end(), in[i]) - vals.begin();
        out[i] = lower_bound(vals.begin(), vals.end(), out[i]) - vals.begin();
    }
    vector<int> pre(4 * 100000 + 3);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        pre[in[i]] += 1;
        pre[out[i] + 1] -= 1;
    }
    for (int i = 0; i <= 2 * n; i++) {
        if(i > 0 ) pre[i] += pre[i-1] ;
        ans = max(ans , pre[i] ) ;
    }
    cout << ans << endl;
}