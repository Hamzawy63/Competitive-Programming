#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
int main() {
    const int N = 61;
    ll dp[N + 3][N + 3];
//    unsigned ll dp2[N + 3][N + 3];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j ) {
                dp[i][j] = 1;
//                dp2[i][j] = 1;
            } else if (j == 1) {
                dp[i][j] = i;
//                dp2[i][j] = i;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
//                dp2[i][j] = dp2[i - 1][j] + dp2[i - 1][j - 1];
            }
//            if(dp[i][j] != dp2[i][j]) {
//                cout << i << " " << j << endl;
//                assert(false);
//            }
        }
    }
    ll m;
    int k;
//    cin >> m >> k;
    cin >> m >> k;
    auto ncr = [&](int n, int r) {
        if (n < r || r <= 0)
            return 0LL;
        ll ans = dp[n][r];
        return ans;
    };
    auto pre = [&](ll n) {
        int bits = 0;
        for (int i = N; i >= 0; i--) {
            if (n & (1LL << i))
                bits += 1;
        }
        int set_bits_so_far = 0;
        ll ans = 0;
        for (int i = N; i >= 0; i--) {
            if (n & (1LL << i)) {
                int remain_bits = i;
                ans += ncr(remain_bits, k - set_bits_so_far);
                set_bits_so_far += 1;
            }
        }
        if (bits == k) ans += 1;
        return ans;
    };
    ll lb = 1, rb = 1000000000000000000;
    ll ans = 0;
    while (lb <= rb) {
        ll mb = (lb + rb) / 2;
        ll count = pre(2 * mb) - pre(mb);
        if (count >= m) {
            ans = mb;
            rb = mb - 1;
        } else if (count < m) {
            lb = mb + 1;
        } else {
            // Will never reach here, Let's get the smallest valid number instead :D
            cout << mb << endl;
            return 0;
        }
    }
    cout << ans << endl;
 
}
