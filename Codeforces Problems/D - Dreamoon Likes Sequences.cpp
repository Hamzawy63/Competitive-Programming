#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <cmath>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int d, m;
        cin >> d >> m;
        if (d == 1) {
            if (m == 1) cout << 0 << endl;
            else cout << 1 << endl;
            continue;
        }
        int maxBit = (int) log2(d) + 1;;
        ll dp[35];
        for (int i = 0; i < 34; i++) dp[i] = 0;
        for (int i = 1; i < maxBit; i++) {
            if (i == 1) dp[1] = 1;
            else dp[i] = 2 * dp[i - 1];
 
            dp[i] %= m ;
        }
        dp[maxBit] = (d - 2 * dp[maxBit - 1] + 1)%m;
        ll res = 1;
        for (int i = 0; i <= 33; i++) {
            res *= ((dp[i] + 1));
            res %= m ;
        }
        cout << max((res - 1 + m)%m, 0LL) << endl;
 
    }
    return 0;
 
}
