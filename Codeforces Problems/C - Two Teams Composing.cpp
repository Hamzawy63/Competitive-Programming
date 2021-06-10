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
int f[2 * 100000 + 4];
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int dis = 0;
        for (int i = 0; i <= n; i++) f[i] = 0;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (f[t] == 0) {
                dis++;
            }
            f[t]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] > dis) ans = max(ans, dis);
            else {
                ans = max(ans, min(f[i] , dis - 1 ));
            }
        }
        cout << ans << endl;
 
 
    }
    return 0;
 
}
