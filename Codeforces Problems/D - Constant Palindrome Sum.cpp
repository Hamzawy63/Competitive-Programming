#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
using namespace std;
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define MOD (int)(1e9  + 7)
#define  ff first
#define  ss second
#define space " "
 
int pre[4 * 100000 + 5];
int mp[4 * 100000 + 5];
 
void solve() {
    IO;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= 2 * k + 1; i++) {
        pre[i] = 0;
        mp[i] = 0;
    }
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; i++) {
        int sum = a[i] + a[n - i - 1];
        mp[sum]++;
        pre[min(a[i], a[n - i - 1]) + 1] += 1;
        pre[max(a[i], a[n - i - 1]) + k + 1] -= 1;
    }
    for (int i = 1; i <= 2 * k; i++) pre[i] += pre[i - 1];
    int ans = INT_MAX;
    for (int i = 2; i <= 2 * k; i++) {
        int res = pre[i];
        res += ((n / 2) - res) * 2;
        res -= mp[i];
        ans = min(ans, res);
    }
    cout << ans << endl;
 
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
//    solve();
 
    return 0;
}
