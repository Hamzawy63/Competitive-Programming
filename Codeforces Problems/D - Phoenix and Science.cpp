#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <sstream>
#include <random>
#include <iterator>
 
typedef long long int ll;
using namespace std;
#define vl vector<ll>
#define vi vector<int>
#define space " "
 
 
void solve() {
    int n;
    cin >> n;
    vi res;
    for (int i = 0; (1 << (i + 1)) - 1 < n; i++) {
        res.push_back(1 << i);
    }
    ll carry = n - (2 * ((*res.rbegin())) - 1);
    if (carry != 0) res.push_back(carry);
    sort(res.begin(), res.end());
    cout << (int) res.size() - 1 << endl;
    for (int i = 1; i < (int) res.size(); i++)cout << res[i] - res[i - 1] << space;
    cout << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
//    solve();
 
    return 0;
}
