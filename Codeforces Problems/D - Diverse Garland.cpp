#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e6
#define MOD (int)1e9
using namespace std;
using namespace std;
 
/**Global stuff */
int dp[(int) 2e5 + E][3];
 
/**Global stuff */
 
int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = (int) 1e6;
 
    dp[0][0] = s[0] != 'R';
    dp[0][1] = s[0] != 'G';
    dp[0][2] = s[0] != 'B';
    vector<char> cur = {'R', 'G', 'B'};
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int cost = (s[i] != cur[j]);
            int c1 = dp[i - 1][(j + 1) % 3] + cost;
            int c2 = dp[i - 1][(j + 2) % 3] + cost;
            dp[i][j] = min(c1, c2);
        }
    }
    int opt = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    cout << opt << endl;
    string res = "";
    int j = -1;
    if (dp[n - 1][0] == opt) {
        res.push_back('R');
        j = 0;
    } else if (dp[n - 1][1] == opt) {
        res.push_back('G');
        j = 1;
    } else if (dp[n - 1][2] == opt) {
        res.push_back('B');
        j = 2;
    }
    for (int i = n - 2; i >= 0; i--) {
       if(dp[i][(j+1)%3]  < dp[i][(j+2)%3] )
       {
           res.push_back(cur[(j+1)%3]) ;
           j = (j+1)%3;
       }else {
           res.push_back(cur[(j+2)%3]) ;
           j = (j+2)%3;
       }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
 
    return 0;
}
