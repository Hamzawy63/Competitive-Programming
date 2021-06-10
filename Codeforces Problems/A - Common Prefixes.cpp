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
    vi a(n);
    int len = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        len = max(len, a[i]);
    }
    vector<string> res;
    string t = "";
    char nxt = 0;
    for (int i = 0; i < len; i++) {
        t += 'a' + (nxt++);
        nxt %= 26;
    }
    res.pb(t) ;
    for (int i = 0; i < n; i++) {
         t = "";
        for (int j = 0; j < a[i]; j++) {
            t += res[i][j];
        }
        for (int j = a[i]; j < len; j++) {
            if (res[i][j] == 'z') t += 'a';
            else
                t += (char) (res[i][j] + 1);
        }
        res.pb(t) ;
    }
    for(auto s : res) cout << s << endl;
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //   cout << "Case #" << i << ": ";
        solve();
    }
}
