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
 
template<typename T>
// remove all occurrences of item in the container v
inline void remove(vector<T> &v, const T &item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}
 
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<char> l;
    int ans = n;
    for (int i = 0; i < n;) {
        char last = '*';
        if (!l.empty()) last = l.back();
        if (last == '*' && i < n - 1) {
            bool ff = (s[i] == 'A') && (s[i + 1] == 'B');
            bool ss = (s[i] == 'B') && (s[i + 1] == 'B');
            if (ff || ss) {
                ans -= 2;
                i += 2;
            }else {
                l.push_back(s[i]) ;
                i++ ;
            }
        } else if (last == 'A' && s[i] == 'B') {
            l.pop_back();
            ans -= 2;
            i++;
        } else if (last == 'B' && s[i] == 'B') {
            ans -=2 ;
            l.pop_back();
            i++ ;
        }else {
            l.push_back(s[i]) ;
            i++ ;
        }
    }
    cout <<ans <<endl;
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
