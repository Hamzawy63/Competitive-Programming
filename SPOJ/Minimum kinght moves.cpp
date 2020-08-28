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
const vector<int> dx = {-2, -2, 2, 2, 1, -1, 1, -1};
const vector<int> dy = {1, -1, 1, -1, -2, -2, 2, 2};

void solve() {
    string s, t;
    cin >> s >> t;
//    cerr << s << t << endl;
    int rs = '8' - s[1], cs = s[0] - 'a';
    int rt = '8' - t[1], ct = t[0] - 'a';
    /*if (rs == rt && cs == ct) {
        cout << 0 << endl;
        return;
    }*/
    vector<vector<int>> vis(8, vector<int>(8, 0));
    int ans = -1;
    queue<pair<int, int>> q;
    q.push({rs, cs});
    vis[rs][cs] = 0;
    while (!q.empty()) {
        ans++;
        int sz = (int) q.size();
        while (sz--) {
            int r = q.front().ff;
            int c = q.front().ss;
            if (r == rt && c == ct) {
                cout << ans << endl;
                return;
            }
            q.pop();
            for (int i = 0; i < 8; i++) {
                int rr = r + dx[i];
                int cc = c + dy[i];
                if (rr >= 0 && cc >= 0 && rr < 8 && cc < 8 && !vis[rr][cc]) {
                    vis[rr][cc] = 1;
                    q.push({rr, cc});
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int q = 1;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}