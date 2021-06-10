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
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 10
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e7)
using namespace std;
 
int main() {
    IO;
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        bool ok = true;
        vector<char> ans;
        int ptr = 0;
        int vis[27];
        for (int i = 0; i < 26; i++) vis[i] = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (ans.empty()) {
                ans.push_back(s[i]);
                vis[s[i] - 'a'] = 1;
                ptr = 0;
            } else if (ptr < ans.size() - 1 && ans[ptr + 1] == s[i]) {
                ptr++;
            } else if (ptr > 0 && ans[ptr - 1] == s[i])
                ptr--;
            else if (ptr == 0 && !vis[s[i] - 'a']) {
                ans.insert(ans.begin(), s[i]);
                vis[s[i] - 'a'] = 1;
 
            } else if (ptr == (int) ans.size() - 1 && !vis[s[i] - 'a']) {
                ans.push_back(s[i]);
                vis[s[i] - 'a'] = 1;
                ptr++ ;
 
            } else {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < (int) ans.size(); i++) cout << ans[i];
            for (int i = 0; i < 26; i++) if (vis[i] == 0) cout << (char) (i + 'a');
            cout << endl;
 
        }
 
 
    }
    return 0;
}
