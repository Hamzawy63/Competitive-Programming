#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = 1000000007 ;
ll powmod(ll a , ll b ) {
    ll res = 1;
    while(b > 0 ) {
        if(b&1) {
            res = res * a ;
            res %= Mod ;
        }
        b >>=1 ;
        a = a * a ;
        a %= Mod ;
    }
    return res ;
}
void solve() {
    int n;
    cin >> n ;
    vector<ll> fac(n+2) , dp(n+4 ) ;
    fac[0] = 1 ;
    for(ll i=1;i<=n;i++){
        fac[i] = fac[i-1] * i ;
        fac[i] %= Mod ;
    }//641102369
    dp[3] = 4 ;
    for(ll i=4;i<=n;i++){
        dp[i] = dp[i-1] * 2 ;
        dp[i] %= Mod ;
    }
    cout << ((fac[n] - dp[n])%Mod + Mod)%Mod << endl;
}
//#define _DEBUG
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
