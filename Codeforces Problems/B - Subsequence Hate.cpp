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
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
 
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    int suf0 =0,suf1 =0 ;
    for(int i=0;i<n;i++ ){
        suf0 += s[i] == '0' ;
        suf1 += s[i] == '1' ;
    }
    int pre0 =0,pre1 =0;
    int ans = min(suf0 ,suf1) ;
    for(int i=0;i<n;i++ ){
        pre0 += s[i] == '0' ;
        pre1 += s[i] == '1' ;
        suf0 -= (s[i] == '0') ;
        suf1 -= (s[i] == '1') ;
        ans = min(ans , pre0 + suf1) ;
        ans = min(ans , pre1 +suf0) ;
    }
    cout << ans << endl;
 
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}
