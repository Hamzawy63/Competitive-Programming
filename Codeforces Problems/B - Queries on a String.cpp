#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
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
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
 
void solve() {
    string s ;
    cin >> s ;
    int q ;
    cin >> q ;
    while(q--) {
        int l , r , k ;
        cin >> l >> r >> k ;
        k %= (r - l + 1 ) ;
        l--;r--;
        if(k != 0 ) {
            string t = s.substr(l , r - l + 1 ) ;
            int m = (int)t.size();
            int st = m - k ;
            for(int i=l ; i <= r ;i++){
                s[i] = t[st];
                st = (st + 1 ) % m ;
            }
        }
    }
    cout << s << endl;
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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
