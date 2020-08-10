#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void solve() {
    int n;
    cin >> n;
    string I, O;
    cin >> I >> O;
    int g[n + 1][n + 1], res[n + 1][n + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) g[i][j] = 1;
            else if (O[i] == 'Y' && I[j] == 'Y' && abs(i - j) == 1) g[i][j] = 1;
            else {
                g[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> vis(n);
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (g[cur][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                    res[i][j] = 1;
                }
            }

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ((res[i][j] == 1 ) ? 'Y':'N');
        }
        cout << endl;
    }

}
#define _DEBUG
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cout << "Case #" << i << ": " << endl;
        solve();
    }
}
