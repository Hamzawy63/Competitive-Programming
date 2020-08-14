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
const int maxN = 2 * 100 * 1000;
int table[60][maxN];

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; (1 << i) <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + (1 << i) > n) continue;
            if (i == 0) table[i][j] = a[j];
            else {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        int exp = (int) log2(r - l + 1);
        cout << min(table[exp][l], table[exp][r - (1 << exp) + 1 ]) << endl;
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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}