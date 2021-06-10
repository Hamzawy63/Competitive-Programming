#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)
ll a[300000 + 2], b[300000 + 2];
ll pay[300000 + 2];
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO ;
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            if (i > 0) {
                pay[i] = max(0LL, a[i] - b[i - 1]);
                sum += pay[i];
            }
        }
        pay[0] = max(0LL, a[0] - b[n - 1]);
        sum += pay[0];
        ll ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, a[i] + sum - pay[i]);
        }
        cout << ans << endl;
 
    }
 
    return 0;
}
