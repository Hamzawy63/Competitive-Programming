#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
int main() {
    int n;
    cin >> n;
    int res = 0;
    vector<int> a(n), ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        ans.pb(a[i]);
        if (__gcd(a[i], a[i + 1]) != 1) {
            res++;
            ans.pb(1);
        }
    }
    ans.pb(a.back()) ;
    cout << res << endl;
    for(auto v : ans) {
        cout << v << space ;
    }
    cout <<endl;
 
}
