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
#define FINF 1000000000000
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int N = 4 * 1e5 + 2;
 
 
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    if (n == 1) {
        cout << "No" << endl;
        return;
    }
    vector<char> ans;
    char last = '*';
    for (int i = 0; i < n; i++) {
        if (ans.empty()) {
            ans.pb(s[i]);
        } else {
            if (ans.back() == s[i]) {
                ans.pop_back();
            } else {
                ans.push_back(s[i]);
            }
        }
    }
    bool ok = (n%2 == 0 ) ;
    if(ans.size() > 1)
        ok = false ;
 
    if(ok) cout << "Yes" <<endl;
    else cout << "No" <<endl;
}
 
int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
