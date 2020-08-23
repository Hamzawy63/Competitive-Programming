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
 
int main() {
    int n, k;
    cin >> n >> k;
    map<ll, int> mp;
    ll sum = 0;
    mp[0]++;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
        ans += mp[sum - k];
        mp[sum]++;
    }
    cout << ans << endl;
}