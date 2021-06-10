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
    int n, k;
    cin >> n >> k;
    vi a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    if((int)st.size() > k ) {
        cout << -1 << endl;
        return;
    }
    for(auto i : st) {
        a.insert(a.begin() , i) ;
    }
 
    for (int i = k; i < (int)a.size() ;i++) {
         if (a[i] != a[i - k])
            a.insert(a.begin() + i, a[i - k]);
    }
        cout << (int) a.size() << endl;
        for (auto i : a) cout << i << space;
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
