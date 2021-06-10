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
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;
 
 
/**Global stuff */ ;
ll dp[2009][2009];
vi arr[2009];
 
/**Global stuff */
 
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                arr[i].push_back(j);
                if (j * j != i)
                    arr[i].push_back(i / j);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 0 ;
            if (i == 1) dp[i][j] = 1;
            else {
                for (auto l : arr[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
                }
            }
        }
    }
    ll res = 0 ;
    for(int i = 1 ; i <= n ; i++ ){
        res = (res + dp[k][i]) % MOD ;
    }
    cout << res << endl;
    return 0;
}
