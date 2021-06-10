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
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int N = 315 ; //316;
const int maxN = 1e5;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto get_block = [&](int n) {
        return n / N;
    };
    vector<int> nxt(n);
    vector<int> count(n);
    vector<int> idx(n);
    auto edit = [&](int i) {
        if (i + a[i] >= n) {
            idx[i] = i;
            nxt[i] = n;
            count[i] = 1;
        } else {
            int blk1 = get_block(i);
            int blk2 = get_block(i + a[i]);
            if (blk2 > blk1) {
                nxt[i] = i + a[i];
                count[i] = 1;
            } else {
                nxt[i] = nxt[i + a[i]];
                count[i] = 1 + count[i + a[i]];
            }
            idx[i] = idx[i + a[i]];
        }
    };
 
    for (int i = n - 1; i >= 0; i--) {
        edit(i);
    }
//    for (auto v : nxt) {
//        cerr << v << space;
//    }
//    cerr << endl;
//    for (auto v : count) {
//        cerr << v << space;
//    }
//    cerr << endl;
//    for (auto v : idx) {
//        cerr << v << space;
//    }
//    cerr << endl;
 
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t) {
            int aa;
            cin >> aa;
            aa--;
            int ans = 0;
            int last = 0;
            while (aa < n) {
                last = idx[aa] ;
                ans += count[aa];
                aa = nxt[aa];
            }
            cout << last + 1  << space << ans << '\n';
        } else {
            int aa, bb;
            cin >> aa >> bb;
            aa--;
            a[aa] = bb;
            int blk = get_block(aa);
            int first = blk * N;
            for (int j = aa; j >= first; j--) {
                edit(j);
            }
        }
    }
 
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
