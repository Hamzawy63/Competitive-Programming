#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
using namespace std;
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define MOD (int)(1e9  + 7)
#define  ff first
#define  ss second
#define space " "
 
pair<ll, ll> bezout(ll a, ll b) {
    if (b == 0) return {1, 0};
    pair <ll, ll> nxt = bezout(b, a % b);
    return {nxt.ss, nxt.ff - (a / b) * nxt.ss};
}
 
ll powmod(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}
 
vii mat_mul(vii a, vii b) {
    int mod = (int) MOD;
    int n = a.size();
    int m = b[0].size();
    vii res(n, vi(m));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = 0;
            for (int k = 0; k < (int) a[0].size(); k++) {
                res[i][j] += (a[i][k] * 1ll * b[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}
 
 
void solve() {
    ll n;
    cin >> n;
    if(((n/2) % 2) == 1 )
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        ll sum = 0 ;
        ll nxtE = 2 ;
        ll nxtO = 1 ;
        for(int i = 0 ;i < n/2 ; i++ ) {
            cout << nxtE << space ;
            sum += nxtE ;
            nxtE += 2 ;
        }
        for(int i = 0 ; i < (n/2 - 1) ; i++ ){
            cout << nxtO <<space ;
            sum -= nxtO ;
            nxtO += 2 ;
        }
        cout << sum << endl ;
    }
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
//    solve();
 
    return 0;
}
