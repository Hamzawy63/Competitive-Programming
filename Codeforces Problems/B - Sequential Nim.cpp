#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
 
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
void solve() {
    int n;
    cin >> n;
    vi a(n), dp(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            dp[i] = 1;
        } else if (i == n - 2) {
            if (a[i] == 1) dp[i] = 0;
            else dp[i] = 1;
        } else {
            if (a[i] == 1) dp[i] = !dp[i + 1];
            else dp[i] = 1;
        }
    }
    if(dp[0] == 1 ) cout << "First" << endl;
    else cout << "Second" << endl;
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    pre();
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //   cout << "Case #" << i << ": ";
        solve();
    }
}
