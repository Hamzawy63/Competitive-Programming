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
 
template<typename T>
// remove all occurrences of item in the container v
inline void remove(vector<T> &v, const T &item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}
 
void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 01 - 10 - (n-1, n-2) - (n-2 , n-1)
    int f = a[0][1] - '0';
    int s = a[1][0] - '0';
    int t = a[n - 1][n - 2] - '0';
    int fo = a[n - 2][n - 1] - '0';
   // cerr << f << space << s << space << t << space << fo << endl;
    vector<pair<int, int> > idx = {{1,     2},
                                   {2,     1},
                                   {n , n - 1},
                                   {n - 1, n}};
    for (int i = 0; i < 16; i++) {
        vi change = {f, s, t, fo};
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (((1 << j) & i)) {
                cnt++;
                change[j] = (1 ^ change[j]);
            }
 
        }
        if (cnt <= 2) {
            if ((change[0] == change[1]) && (change[2] == change[3]) && (change[1] != change[2])) {
                cout << cnt << endl;
                if (change[0] != f) {
                    cout << idx[0].first << space << idx[0].second << endl;
                }
                if (change[1] != s) {
                    cout << idx[1].first << space << idx[1].second << endl;
                }
                if (change[2] != t) {
                    cout << idx[2].first << space << idx[2].second << endl;
                }
                if (change[3] != fo) {
                    cout << idx[3].first << space << idx[3].second << endl;
                }
                return;
            }
        }
    }
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
