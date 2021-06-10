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
const double eps = 0.0000001;
const int maxN = 10000000;
 
void solve() {
    int n ;
    cin >> n ;
    ll res = 0 ;
    ll cubes = 8 ;
    for(int i = 1 ; i <= n/2 ; i++ ){
        res += cubes * i ;
        cubes += 8 ;
    }
    cout << res << endl;
 
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
        solve();
        //cout << "Case #" << i << ": ";
    }
}
