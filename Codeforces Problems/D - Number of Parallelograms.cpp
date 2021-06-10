#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
const double inf = 2e18;
#define EPS  0.0000000001
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> middle = {(a[i].first + a[j].first), (a[i].second + a[j].second)};
            mp[middle]++ ;
        }
    }
    ll ans=0;
    for(auto v : mp) {
        ans += (v.second * 1LL * (v.second-1))/2;
    }
    cout<<ans<<endl;
 
 
}
