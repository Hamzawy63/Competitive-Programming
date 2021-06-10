#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
const double eps = 0.0000001;
 
map<int, vi > mp;
 
void add(int p, int val) {
    mp[p].push_back(val);
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t % 2 == 0) {
            int ex = 0;
            while (t % 2 == 0) {
                t /= 2;
                ex++;
            }
            add(2, ex);
        }
        for (ll j = 3; j * j <= t; j += 2) {
            if (t % j == 0) {
                int ex = 0;
                while (t % j == 0) {
                    t /= j;
                    ex++;
                }
                add(j, ex);
            }
        }
        if (t != 1) {
            add(t, 1);
        }
    }
    ll ans = 1;
    for (auto itr : mp) {
        int p = itr.first;
        vi list = itr.second;
        if (n - (int) list.size() < 2) {
            int i = 2 - (n - (int) list.size())-1;
            nth_element(list.begin(), list.begin() + i, list.end()) ;
            ans *= (int)pow(p , list[i]) ;
        }
    }
    cout << ans << endl;
}
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder 
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int q = 1;
    //scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}
