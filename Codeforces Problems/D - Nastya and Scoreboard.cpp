#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
typedef long long int ll;
using namespace std;
 
#define vi vector<int>
const int Mod = 1000000007;
const int maxN = 2005;
const vector<string> seg = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010",
                            "1111111", "1111011"};
int need[maxN][12];
int dp[maxN][maxN];
 
void solve() {
    int n, kk;
    cin >> n >> kk;
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        string s = arr[i];
        for (int j = 0; j < 10; j++) {
            int cost = 0;
            for (int k = 0; k < 7; k++) {
                if (s[k] == '0' && seg[j][k] == '1') cost++;
                else if (s[k] == '1' && seg[j][k] == '0') {
                    cost = -1;
                    break;
                }
            }
            need[i][j] = cost;
        }
    }
 
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j <= 9; j++) {
//            cerr << need[i][j] << " ";
//        }
//        cerr << endl;
//    }
 
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= kk; j++) {
            dp[i][j] = -1;
            for (int k = 9; k >= 0; k--) {
                int cost = need[i][k];
                if (i == 0) {
                    if (need[0][k] != -1) dp[0][need[0][k]] = max(k, dp[0][need[0][k]]);
                } else if (cost != -1 && (j - cost) >= 0 && dp[i - 1][j - cost] != -1) {
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }
//    cerr << "Now we are debugging the dp array \n";
//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k <= kk; k++) {
//            cerr << dp[i][k] << " ";
//        }
//        cerr << endl;
//    }
    if (dp[n - 1][kk] == -1) cout << -1 << endl;
    else {
        string res = "";
        int i = n - 1, j = kk;
        while (i > -1) {
            res += (char) (dp[i][j] + '0');
            j -= need[i][dp[i][j]];
            i--;
        }
        //reverse(res.begin(), res.end());
        cout << res << endl;
    }
 
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        // cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();
 
    return 0;
}
