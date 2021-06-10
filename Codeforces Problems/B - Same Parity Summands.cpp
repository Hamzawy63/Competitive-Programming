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
        int n, k;
        cin >> n >> k;
        if (k > n) {
            cout << "NO" << endl;
        } else {
            int allOdd = 1 * (k - 1);
            int allEven = 2 * (k - 1);
            if ((n > allEven) && ((n - allEven) % 2 == 0)) {
                cout << "YES" << endl;
                for (int i = 0; i < k - 1; i++) cout << 2 << space;
                cout << n - allEven << endl;
            } else if ((n > allOdd) && ((n - allOdd) % 2 == 1)) {
                cout << "YES" << endl;
                for (int i = 0; i < k - 1; i++) cout << 1 << space;
                cout << n - allOdd << endl;
            }else {
                cout << "NO" << endl;
            }
        }
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
