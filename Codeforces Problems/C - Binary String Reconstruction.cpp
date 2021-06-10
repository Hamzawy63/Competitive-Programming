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
    string s;
    cin >> s;
    int n = (int) s.size();
    int x;
    cin >> x;
    vector<char> res(n, '*');
    bool ok = true;
    for (int i = 0; (i - x < 0) && (i + x < n); i++) {
        if (s[i] == '1' && res[i + x] != '0') {
            res[i + x] = '1';
        } else if (s[i] == '0' && res[i + x] != '1') {
            res[i + x] = '0';
        } else {
            ok = false;
        }
    }
    for (int i = n - 1; (i - x >= 0) && (i + x >= n); i--) {
        if (s[i] == '1' && res[i - x] != '0') {
            res[i - x] = '1';
        } else if (s[i] == '0' && res[i - x] != '1') {
            res[i - x] = '0';
        } else {
            ok = false;
        }
    }
 
    for (int i = 0; i < n; i++) {
        if ((i - x >= 0) && (i + x < n)) {
            if (s[i] == '0' && res[i - x] != '1' && res[i + x] != '1') {
                res[i + x] = '0';
                res[i - x] = '0';
            } else if (s[i] == '0') {
                ok = false;
            } else if (s[i] == '1') {
                if (res[i + x] == '0' && res[i - x] == '0') ok = false;
                else if (res[i - x] != '0') res[i - x] = '1';
                else if (res[i + x] != '0') res[i + x] = '1';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if ((i + x >= n) && (i - x < 0)) ok = false;
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
 
    for (int i = 0; i < n; i++) {
        if (res[i] == '*')
            cout << '1';
        else
            cout << res[i];
    }
    cout << endl;
 
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
