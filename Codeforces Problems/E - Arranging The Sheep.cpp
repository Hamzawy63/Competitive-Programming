#include <bits/stdc++.h>
/*
Created on  by Hamza Hassan
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
    string s;
    cin >> s;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<long long int> pre(n), suf(n);
    int cnt = (s[0] == '*');
    pre[0] = 0;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '.') {
            pre[i] += cnt;
        } else {
            cnt += 1;
        }
    }
    cnt = (s[n - 1] == '*');
    suf[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == '.') {
            suf[i] += cnt;
        } else {
            cnt++;
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i + 1 < n; i++) {
        ans = min(ans, pre[i] + suf[i + 1]);
//        if (s[i] == '*' && i )
//            ans = min(ans, pre[i - 1] + suf[i + 1]);
    }
//    for(auto v  :pre ){
//        cerr << v << ' ';
//    }
//    cerr << endl;
//    for(auto v : suf) {
//        cerr << v<< ' ' ;
//    }
//    cerr << endl;
    ans = min(ans, suf[0]);
    ans = min(ans, pre[n - 1]);
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
