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

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        vector<int> ans;
        int res = 0;
        while (x % 2 == 0) {
            res++;
            x /= 2;
        }
        ans.pb(res);
        for (ll i = 3; i * i <= x; i += 2) {
            if (x % i == 0) {
                res = 0;
                while (x % i == 0) {
                    res++;
                    x /= i;
                }
                ans.pb(res);
            }
        }
        if (x > 1) {
            ans.pb(1);
        }
        ll final = 1;
        for (auto v : ans) {
            final *= (1 + v);
        }
        cout << final << endl;
    }
}