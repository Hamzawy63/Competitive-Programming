#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const int Mod = 1000000000 + 7;

int powmod(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % mod;
        }
        b >>= 1;
        a = (a * 1ll * a) % mod;
        a %= mod;
    }
    return res;
}

const int maxN = 2000000 + 2;
int f[maxN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        f[t] ++ ;
    }
    int ans = 0;
    for (int i = 2; i <= (int) 2e6; i++) {
        int cnt = f[i] ;
        for (int j = i * 2; j <= (int) 2e6; j += i) {
            cnt += f[j];
            if (cnt > 1) {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
}