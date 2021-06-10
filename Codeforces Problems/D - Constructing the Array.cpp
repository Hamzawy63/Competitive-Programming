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
 
bool valid(pair<int, int> p) {
    return p.second >= p.first;
}
 
int len(pair<int, int> p) {
    return p.second - p.first + 1;
}
 
const int maxN = 2 * 100000;
set<pair<int, int >> a[maxN + 2];
multiset<int> st;
 
void solve() {
    int n;
    cin >> n;
    vi res(n);
    st.insert(n);
    a[n].insert({0, n - 1});
    for (int i = 0; i < n; i++) {
        int nxtMax = *st.rbegin();
        st.erase(st.lower_bound(nxtMax));
        pair<int, int> nxt = *(a[nxtMax].begin());
        a[nxtMax].erase(a[nxtMax].begin());
        int idx = nxt.first + (nxt.second - nxt.first) / 2;
        res[idx] = i + 1;
        pair<int, int> left = {nxt.first, idx - 1};
        pair<int, int> right = {idx + 1, nxt.second};
 
        if (len(left) > 0) {
            a[len(left)].insert(left);
            st.insert(len(left));
        }
        if (len(right) > 0) {
            a[len(right)].insert(right);
            st.insert(len(right)) ;
        }
    }
 
//    set<pair<int, int >> st;
//    set<pair<int, pair<int, int >>> st;
//    st.insert(make_pair(n, make_pair(0, n - 1)));
//    vi res(n);
//    for (int i = 0; i < n; i++) {
//        pair<int, int> nxt = (*st.end()).second;
//        int idx = nxt.first + (nxt.second - nxt.first) / 2;
//        res[idx] = i + 1;
//        st.erase(st.end());
//        pair<int, int> left = {nxt.first, idx - 1};
//        pair<int, int> right = {idx + 1, nxt.second};
//
//        if (valid(left)) st.insert(left);
//        if (valid(right)) st.insert(right);
//    }
    for (int i = 0; i < n; i++)cout << res[i] << space;
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
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}
