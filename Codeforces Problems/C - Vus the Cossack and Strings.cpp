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
const int N = 4 * 1e5 + 2;
 
void solve() {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    int diff = 0;
    int ans = 0;
    int ch = 0;
    for (int i = 0; i < m; i++) {
        diff += (s[i] != t[i]);
        if (i + 1 < n)
            ch += (s[i] != s[i + 1]);
    }
    int L = 1, R = m;
 
    while (R < n) {
        ans += (diff % 2 == 0);
        diff += ch;
        if (s[L] != s[L - 1]) {
            ch--;
        }
        if (R + 1 < n && s[R] != s[R + 1]) {
            ch++;
        }
        R++ ;
        L++ ;
    }
    ans += (diff % 2 == 0);
    cout << ans <<endl;
 
}
 
int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
