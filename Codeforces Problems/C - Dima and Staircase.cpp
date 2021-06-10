#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const int maxN = 3e5 + 3;
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    ll last = 0;
    int q;
    cin >> q;
    while (q--) {
        int w , h ;
        cin >> w >> h ;
        w-- ;
        cout << max(last , a[w] ) <<endl;
        last = h + max(last , a[w]) ;
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    //  cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
