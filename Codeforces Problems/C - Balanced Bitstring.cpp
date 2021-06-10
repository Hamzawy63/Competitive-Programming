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
 
void check(bool ok) {
    if (ok)cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
//#define _DEBUG
void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    bool ok = true;
    vector<set<int>> res(k);
    for (int i = 0; i < n; i++) {
        res[i % k].insert(s[i]);
    }
    int ones = 0, zeros = 0;
    for (int i = 0; i < k; i++) {
        if (res[i].size() == 3) ok = false;
        else if (res[i].size() == 2 && res[i].count('1') && res[i].count('0')) ok = false;
        else if(res[i].count('0')) zeros++ ;
        else if(res[i].count('1')) ones++ ;
    }
    int rest = k - ones - zeros;
    if (abs(ones - zeros) > rest) ok = false;
    check(ok);
 
 
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
