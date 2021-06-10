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
//vi dx = {-1, 0, 0, 1};
//vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
 
void solve() {
    int n, m;
    cin >> n >> m;
    vii a(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (st.count(make_pair(i, j))) {
                continue;
            }
            vi tog;
            tog.push_back(a[i][j]);
 
            if (m - j - 1 != j)
                tog.push_back(a[i][m - j - 1]);
            if (n - i - 1 != i)
                tog.push_back(a[n - i - 1][j]);
            if (n - i - 1 != i && m - j - 1 != j)
                tog.push_back(a[n - i - 1][m - j - 1]);
 
            st.insert({i, j});
            st.insert({i, m - j - 1});
            st.insert({n - i - 1, j});
            st.insert({n - i - 1, m - j - 1});
 
            sort(tog.begin(), tog.end());
            int sz = (int) tog.size();
            int median = tog[sz / 2];
            for (auto v : tog) {
                ans += abs(v - median);
            }
 
        }
    }
    cout << ans << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("hello.txt", "r", stdin);
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
