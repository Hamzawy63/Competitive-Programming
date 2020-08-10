#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
vector<char> dir = {'D', 'R', 'L', 'U'};

void solve() {
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2; // to store the initial and the final points
    vii dp(n, vector<int>(m, 0)); // restore the shortest path length to go from the start point to i , j
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') dp[i][j] = -1;
            else if (s[j] == 'A') {
                x1 = i;
                y1 = j;
                dp[i][j] = 0;
            } else if (s[j] == 'B') {
                x2 = i;
                y2 = j;
            }

        }
    }
    auto valid = [&](int i, int j) {
        return i < n && j < m && i > -1 && j > -1;
    };
    queue<pair<int, int>> q;
    q.push({x1, y1});
    while (!q.empty()) {
        int x = q.front().ff;
        int y = q.front().ss;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            bool isStart = (newX == x1) && (newY == y1);
            if (valid(newX, newY) && dp[newX][newY] == 0 && !isStart) {
                dp[newX][newY] = dp[x][y] + 1;
                q.push(make_pair(newX, newY));
                //cerr << "add i = " << newX << " add j = " << newY << " with len = " << dp[newX][newY] << endl;
            }
        }
    }
    if (dp[x2][y2] != 0) {
        cout << "YES" <<endl;
        cout << dp[x2][y2] << endl;
        string res;
        int x = x2, y = y2;
        // backtracking the dp array to know the path sequence
        while (!(x == x1 && y == y1)) {
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (valid(newX , newY) && dp[newX][newY] + 1 == dp[x][y]) {
                    x = newX;
                    y = newY;
                    res += dir[i];
                    break;
                }
            }
        }
        reverse(res.begin() , res.end()) ;
        cout << res << endl;
    }else {
        cout << "NO" << endl;
        cout << -1 << endl;
    }



}


//#define _DEBUG

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}