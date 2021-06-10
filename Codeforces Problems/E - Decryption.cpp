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
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
//#define _DEBUG
const int maxN = 2001;
ll inf = 1e14;
 
 
void solve() {
    int n;
    cin >> n;
    int nn = n;
    vector<int> p;
    if (n % 2 == 0) {
        int exp = 0;
        while (n % 2 == 0) {
            n /= 2;
            exp++;
        }
        p.push_back(2);
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int exp = 0;
            while (n % i == 0) {
                n /= i;
                exp++;
            }
            p.push_back(i);
        }
    }
    if (n != 1) {
        p.push_back(n);
    }
    n = nn;
    int sz = (int) p.size();
    if (sz == 2) {
        if (p[0] * p[1] == n) {
            //cerr << "Case 1 " <<endl;
            cout << p[0]  << space << p[1] << space << n << endl;
            cout << 1 << endl;
        } else {
            //cerr << "Case 2 " <<endl;
            vector<int> ans = {p[0], n, p[1]};
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    if (i != p[0] && i != p[1])
                        ans.push_back(i);
                    if (i != n / i)
                        if ((n / i) != p[0] && (n / i) != p[1])
                            ans.push_back(n/i);
 
                }
            }
            for (auto v : ans) cout << v << space;
            cout << endl << 0 << endl;
        }
        return;
    }
 
 
    vector<vector<int>> ans1(sz);
    vector<vector<int>> ans2(sz);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            for (int div : {i, n / i}) {
                bool ok = false;
                for (int j = 0; !ok && j < sz; j++) {
                    int p1 = p[j];
                    int p2 = p[(j + 1) % sz];
                    if (div % (p1 * p2) == 0 ) {
                        ans2[j].push_back(div);
                        ok = true;
                    }
                }
                for (int j = 0; !ok && j < sz; j++) {
                    int p1 = p[j];
                    if (div % (p1) == 0 ) {
                        ans1[j].push_back(div);
                        ok = true;
                    }
                }
                if (i == n / i) break;
            }
        }
    }
    for (int i = 0; i < sz; i++) {
        for (auto v : ans1[i]) cout << v << space;
        for (auto v : ans2[i]) cout << v << space;
    }
    cout << nn << endl;
    cout << 0 << endl;
}
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
