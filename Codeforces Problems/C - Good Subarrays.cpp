#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
//#define _DEBUG
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi pre(n);
    map<int, int> mp;
    mp[1] = 1 ;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        pre[i] = s[i] - '0';
        if (i > 0) pre[i] += pre[i - 1];
        mp[pre[i] - i]++;
//        if (s[i] == '1' && i > 0 )
//            ans++;
//        if (pre[i] == i + 1)
//            ans++;
    }
    for (auto p : mp) {
        ans += (p.ss * 1ll * (p.ss - 1)) / 2;
    }
    cout << ans << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
