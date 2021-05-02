#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
const int maxN = 500 * 500 + 3;
const ll inf = 1e14;

int powmod(int a, int b, int mod) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * 1LL * a) % mod;
        }
        b >>= 1;
        a = (a * 1LL * a) % mod;
    }
    return ans;
}

ll dp[maxN];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    const int Mod = 1e9 + 7;
    if (((n * (n + 1)) / 2) % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = (n * (n + 1) / 2); j >= i; j--) {
            dp[j] = (dp[j] + (dp[j - i])) % Mod;
        }
//        for (int j = 1; j <= (n * (n + 1) / 2); j++) {
//            cerr << dp[j] << space;
//        }
//        cerr << endl;
    }
    int s = (n * (n + 1)) / 4;
    cout << (dp[s] *1ll* powmod(2, Mod - 2 , Mod))%Mod << endl;

}