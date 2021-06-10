#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <unordered_map>
 
typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(12)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
//#define _DEBUG
ll dp[1000005];
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        char ls = 'z';
        for (int i = 0; i < n; i++) {
            if (s[i] < ls) ls = s[i];
        }
        set<pair<string, int >> st;
        //st.insert(make_pair(s  , 1)) ;
        for (int i = 0; i < n; i++) {
            if (s[i] == ls) {
                string ans = s.substr(i, n - i);
                if ((n - i) % 2 == 0) {
                    for (int j = 0; j < i; j++) ans += s[j];
                } else {
                    for (int j = i - 1; j >= 0; j--) ans += s[j];
                }
                st.insert(make_pair(ans, i + 1));
            }
        }
        pair<string, int> res = *st.begin();
        cout << res.first << endl;
        cout << res.second << endl;
 
    }
    return 0;
}
