#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define speed() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e18 + 18;
const int mxN = 1e5, mxM = 1e6, MOD = 1e9 + 7;
 
int n;
 
void solve() {
 
    cin >> n; vector<ar<int,2>> v;
    for (int i = 0; i < n; ++i) {
        int a,b; cin >> a >> b;
        v.push_back({a,1}); v.push_back({b,-1});
    }
    sort(v.begin(),v.end()); int year = 0,res = 0,counter = 0;
    for (ar<int,2> ele : v) {
 
        if (ele[1] == 1) {
            counter++;
        } else {
            counter--;
        }
        if (counter > res) {
            res = counter;
            year = ele[0];
        }
 
    }
    cout << year << " " << res << endll;
}
 
int main() {
    speed()
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
