#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3) {
        cout << 0 << endl;
    }
    ll ans = 0;
    int cnt = 1;
    vector<int> p;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            p.pb(cnt);
            cnt = 1;
        }
    }
    p.pb(cnt);
    if ((int) p.size() == 1) {
        cout << (int) ceil(n / (double) 3) << endl;
        return;
    }
    for (int i = 1; i < (int) p.size() - 1; i++) {
        ans += p[i] / 3;
    }
    if (s[0] == s[n - 1]) ans += (p[0] + p[(int) p.size() - 1]) / 3;
    else ans += ((p[0] / 3) + (p[(int) p.size()-1] / 3));
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}
