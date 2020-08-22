#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array

int main() {
    ll ans = 0;
    int n;
    cin >> n;
    vector<ar<int, 2>> a;
    for (int i = 0; i < n; i++) {
        int duration, deadline;
        cin >> duration >> deadline;
        a.pb({duration, deadline});
    }
    sort(a.begin() , a.end()) ;
    ll finish = 0 ;
    for(int i=0;i<n;i++){
        finish += a[i][0] ;
        ans += a[i][1] - finish ;
    }
    cout << ans << endl;
}