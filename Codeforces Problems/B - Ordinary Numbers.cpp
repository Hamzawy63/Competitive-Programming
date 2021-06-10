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
 
const bool query = true;
 
void solve() {
    int n;
    cin >> n;
    int res =0  ;
    for (int dig = 1; dig <= 9; dig++) {
        ll ans = 0;
        for (int cnt = 1; cnt < 10; cnt++) {
            ans *= 10;
            ans += dig;
            if (ans <= n) {
                res += 1 ;
            }
        }
    }
    cout << res << endl;
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
