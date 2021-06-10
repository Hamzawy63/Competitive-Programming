#include <bits/stdc++.h>
/*
Created on  by Hamza Hassan:
*/
#define space " "
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
using namespace std;
 
void read(vector<int> &a, int n = -1);
 
void print(vector<int> &a, int n = -1);
 
const bool query = 1;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int need = (i - a[i]);
        ans += mp[need];
        mp[need] += 1;
    }
    cout << ans << endl;
}
 
 
int main() {
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int qq = 1;
    if (query)
        cin >> qq;
    for (int i = 1; i <= qq; i++) {
        solve();
    }
}
 
void read(vector<int> &a, int n) {
    if (n == -1) n = a.size();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
 
void print(vector<int> &a, int n) {
    if (n == -1) {
        n = (int) a.size();
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
