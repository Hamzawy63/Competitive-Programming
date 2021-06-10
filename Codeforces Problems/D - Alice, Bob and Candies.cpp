#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <map>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
 
void solve() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = n - 1;
        int mo = 0, alice = 0, bob = 0;
        int last = 0;
        bool turn = 0;
        while (l <= r) {
            int ll = 0;
            mo++;
            if (turn == 0) {
                while (l <= r && ll <= last) {
                    ll += a[l];
                    alice += a[l++];
                }
            } else {
                while (l <= r && ll <= last) {
                    ll += a[r] ;
                    bob += a[r--];
                }
            }
            last = ll ;
            turn = !turn;
        }
        cout << mo << space << alice << space << bob << endl;
    }
}
 
//cout << "Case #" << i << ": ";
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
