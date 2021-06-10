#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q--) {
        ll n, l, r;
        cin >> n >> l >> r;
        ll levels[n + 4];
        levels[0] = 0;
        for (int i = 1; i <= n; i++) {
            levels[i] = 2 * (n - i);
            levels[i] += levels[i - 1];
        }
        levels[n] += 1;
        vi ans;
        ll st = 0;
        int levstart = 1;
        for (int i = 1; i <= n; i++) {
            if (l <= levels[i]) {
                st = levels[i - 1] + 1;
                levstart = i;
                break;
            }
        }
        int n1 = 0, n2 = levstart + 1;
        for (ll i = st; i <= r; i++, n1++) {
 
            if (n2 == n + 1) {
                levstart++;
                n2 = levstart + 1;
                n1 = 0;
            }
            if (levstart >= n) {
                ans.push_back(1);
                break;
            }
 
 
 
 
            if (n1 % 2 == 0)
                ans.push_back(levstart);
            else
                ans.push_back(n2++);
        }
        l -= st;
        r -= st;
        for (int i = l; i <= r; i++) cout << ans[i] << space;
        cout << endl;
 
 
    }
 
 
    return 0;
}
