#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
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
    IO;
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int need = 0;
        pair<int, int> feed = {0, 0};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int ones = 0, zeros = 0;
            for (int j = 0; j < (int) s.size(); j++) {
                if (s[j] == '1') ones++;
                else zeros++;
            }
            ones %= 2;
            zeros %= 2;
            if (ones + zeros == 1) {
                if (ones == 1) feed.second++;
                else feed.first++;
            }
            if (ones + zeros == 2) need++;
            else ans++;
 
 
        }
        if (need % 2 == 1) {
            if (feed.first != 0 || feed.second != 0) ans++;
        }
        cout << ans + 2 * (need / 2) << endl;
    }
 
    return 0;
}
