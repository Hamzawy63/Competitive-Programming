#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll '\n'
#define ar array
 
const ll INF = 1e9 + 9;
const int MAX = 1e5 + 5;
 
ll n,a[MAX];
 
void solve() {
    
    cin>>n ;
    for (int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int last = 0; ll res = 0;
    for(int i=1; i < n; i++){
        if (a[i] == a[i-1])
            continue;
        ll temp = i - last; last = i;
        res += temp*(temp+1)/2;
    }
    ll temp  = n-last;
    res += (temp)*(temp+1)/2;
    cout << res << endll;
 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;  //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
