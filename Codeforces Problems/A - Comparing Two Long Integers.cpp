#include <bits/stdc++.h>
 
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
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
void solve() {
    string ss, tt;
    cin >> ss >> tt;
    string s = "", t = "";
    int ii = 0;
    while (ss[ii] == '0') ii++;
    for (; ii < (int) ss.size(); ii++) s += ss[ii];
    ii = 0;
    while (tt[ii] == '0') ii++;
    for (; ii < (int) tt.size(); ii++) t += tt[ii];
    int sz1 = (int) s.size();
    int sz2 = (int) t.size();
    if (sz1 > sz2) cout << ">" << endl;
    else if (sz2 > sz1) cout << "<" << endl;
    else {
        int ok = 0;
        for (int i = 0; i < sz1; i++) {
            if (s[i] > t[i]) {
                ok = 1;
                break;
            } else if (s[i] < t[i]) {
                ok = -1;
                break;
            }
        }
        if (ok == 0) cout << "=" << endl;
        else if (ok == -1) cout << "<" << endl;
        else cout << ">" << endl;
    }
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
   // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
