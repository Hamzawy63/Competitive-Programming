#include <bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long
 
 
const int mxN = 103;
int query = 0;
 
void solve() {
    map<ll , int> mp ;
    for(ll i=1;i<=10000;i++){
        mp[i * i * i ] = i ;
    }
    int q;
    cin >> q;
    while (q--) {
        bool ok = false ;
        ll n;
        cin >> n;
        for (ll i = 1; i <= 10000; i++) {
            ll triple = n - i * i * i ;
            if(mp.count(triple)){
                ok = true ;
            }
        }
        if(ok ) cout << "YES" << endl;
        else cout << "NO"<<endl;
 
    }
 
 
}
 
int main() {
//    freopen("in" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    IO;
    int q = 1;
    if (query) cin >> q;
    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
}
