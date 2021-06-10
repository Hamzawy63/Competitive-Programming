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
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    char cur = s[0];
    vi res;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            res.pb(i);
            cnt++;
            cur = s[i];
        }
    }
 
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] != cur) {
            res.pb(i + 1);
            cnt++;
            cur = (cur == '0') ? '1' : '0';
        }
    }
    cout << cnt << space;
    for (auto i : res) cout << i << space;
    cout << endl;
 
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
