#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
const int mxA = 100000;
int pr[mxA + 1];
int dp[mxA + 3][20];
vector<int> primes;
 
void init(int n) {
    for (int i = 0; i <= mxA; i++) {
        pr[i] = 1;
    }
    pr[0] = pr[1] = 0;
    for (int i = 2; i <= mxA; i++) {
        if (pr[i] == 1) {
            pr[i] = n;
            primes.push_back(i);
            for (ll j = i + i; j * j <= mxA; j += i) {
                pr[j] = 0;
            }
 
        }
    }
}
 
int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int n, q;
    cin >> n >> q;
    init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> bad(n + 1);
 
    bad[n] = n;
    for (int i = n - 1; i >= 0; i--) {
        int ans = n;
        int val = a[i];
        for (auto p : primes) {
            if (p * 1LL * p > val)
                break;
 
            if (val % p == 0) {
                while (val % p == 0) val /= p;
                ans = min(ans, pr[p]);
                pr[p] = i;
            }
 
        }
        if (pr[val] != 0) {
            ans = min(ans, pr[val]);
            pr[val] = i;
        }
 
 
        bad[i] = min(ans, bad[i + 1]);
    }
 
 
    for (int i = n; i >= 0; i--) {
        dp[i][0] = bad[i];
        for (int j = 1; j < 17; j++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
 
    while (q--) {
        int L, R;
        cin >> L >> R;
        int ans = 0;
        L--;
        R--;
        for (int i = 16; i >= 0; i--) {
            if (dp[L][i] <= R) {
                ans += (1 << i);
                L = dp[L][i];
            }
        }
 
        cout << ans + 1 << endl;
    }
 
 
    return 0;
}
