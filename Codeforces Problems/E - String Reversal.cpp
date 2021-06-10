#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define endll '\n'
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
 
 
const int maxN = 2e5;
vector<int> bit(maxN + 3);
 
int get(int n) {
    int ans = 0;
    while (n >= 0) {
        ans += bit[n];
        n = (n & (n + 1)) - 1;
    }
    return ans;
}
 
void update(int n, int delta) {
    while (n <= maxN) {
        bit[n] += delta;
        n = (n | (n + 1));
    }
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> g[27];
    for (int i = 0; i < n; i++) {
        g[s[i] - 'a'].insert(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int need = s[n - i - 1] - 'a';
        int nearest = *g[need].begin();
        g[need].erase(g[need].begin());
        int delta = get(nearest);
        ans += (nearest + delta - i);
        if (nearest + delta != i) {
            update(0, 1);
            update(nearest , -1);
        }
    }
    cout << ans <<endl;
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
