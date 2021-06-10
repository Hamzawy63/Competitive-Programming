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
string s;
int n;
 
int get_cost(int l, int r, char c) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (s[i] != c) ans++;
    }
    return ans;
}
 
int get_answer(int l, int r, char c) {
    if(l == r ) {
       // cerr << "solution when l = " << l << " and r = " << r << " and c = " << c << "   is " << get_cost(l , r , c) << endl;
        return get_cost(l , r , c) ;
    }
    int mid = l + (r - l) / 2;
    int cost1 = get_cost(l, mid, c);
    int cost2 = get_cost(mid + 1, r, c);
    int res =  min(cost1 + get_answer(mid + 1, r, (char) (c + 1)), cost2 + get_answer(l, mid, (char) (c + 1)));
   // cerr << "solution when l = " << l << " and r = " << r << " and c = " << c << "   is " << res << endl;
    return res ;
}
 
void solve() {
    cin >> n;
    cin >> s;
    cout << get_answer(0, n - 1, 'a') << endl;
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
