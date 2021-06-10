#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const vector<int> dy = {0, 0, 1, 0, -1, 1, -1, 1, -1};
 
void solve() {
    int maxN = 9;
    char g[10][9][9];
    int n = 8;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            g[0][i][j] = s[j];
        }
    }
    for (int k = 0; k < 8; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[k][i][j] == 'S') {
                    g[k + 1][i + 1][j] = 'S';
                }
                if (g[k + 1][i][j] != 'S') {
                    g[k + 1][i][j] = '.';
                }
            }
        }
    }
 
    set<pair<int, pair<int, int>>> q;
    q.insert({0, {7, 0}});
    bool ok = false;
    while (!q.empty()) {
        int kk = q.begin()->ff;
        int r = q.begin()->ss.ff;
        int c = q.begin()->ss.ss;
        if ((r == 0 && c == 7) || kk == 8) {
            ok = true;
            break;
        }
        q.erase(q.begin());
        for (int i = 0; i < (int) dx.size(); i++) {
            int rr = r + dx[i];
            int cc = c + dy[i];
            if (rr >= 0 && rr < n && cc >= 0 && cc < n)
                if (g[kk + 1][rr][cc] != 'S' && g[kk][rr][cc] != 'S') {
                    q.insert({kk + 1, {rr, cc}});
                }
        }
 
    }
    if (ok) cout << "WIN" << endl;
    else cout << "LOSE" << endl;
 
}
 
int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
