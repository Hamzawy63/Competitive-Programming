#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main() {
    int n ;
    cin >> n ;
    ll ans = n*1ll*(n+1)/2 ;
    for(int i=0;i<n-1;i++){
        int t;
        cin >> t ;
        ans -= t ;
    }
    cout << ans << endl;
}
