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
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
 
void solve() {
    ll p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    // let the mininmum always s
    if (w < s) {
        swap(w, s);
        swap(cs, cw);
    }
    ll ans = 0;
    for (int i = 0; i <= cs; i++) {
        if (i * s > p) break;
        ll pp = p - i * s;
        ll carry = min(cw, pp / w);
        ll cww = cw - carry;
        ll css = cs - i;
        ll carry2 = min(css, f / s);
       // css -= min(css, f / s);
        ll ff = f - min(css, f / s) * s ;
        carry2 += min(ff / w, cww);
        ans = max(ans, carry + carry2 + i);
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}
