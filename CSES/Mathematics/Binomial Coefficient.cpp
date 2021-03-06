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

int mul_inv(int a, int mod) {
    return powmod(a, mod - 2, mod);
}

const int maxN = 1000000;
vector<int> fac(maxN + 3);
vector<int> inv(maxN + 3);

int main() {
    fac[0] = 1;
    inv[0] = mul_inv(fac[0], Mod);
    for (int i = 1; i <= maxN; i++) {
        fac[i] = (i * 1ll * fac[i - 1]) % Mod;
        inv[i] = mul_inv(fac[i], Mod);
    }
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << ((fac[a] * 1ll * inv[b]) % Mod * 1ll * inv[a - b]) % Mod << endl;
    }

    return 0;
}