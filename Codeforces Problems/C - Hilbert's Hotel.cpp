#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
 
 
void solve() {
    int n;
    cin >> n;
    set<ll > st ;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        st.insert((i + ((t % n + n)))%n) ;
    }
    if((int)st.size() == n) cout << "YES" << endl;
    else cout << "NO" << endl;
 
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //cout << "Case #" << i << ": ";
 
        solve();
    }
 
    return 0;
}
