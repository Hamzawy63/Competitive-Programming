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
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int nxt = 0;
    vi res(n), l0, l1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (l1.empty()) {
                l0.pb(i);
                res[i] = ++nxt;
            } else {
                res[i] = res[l1.back()];
                l1.pop_back();
                l0.pb(i) ; 
            }
        } else if (s[i] == '1') {
            if (l0.empty()) {
                l1.pb(i);
                res[i] = ++nxt;
            } else {
                res[i] = res[l0.back()];
                l0.pop_back();
                l1.pb(i) ;
            }
        }
    }
    cout << nxt << endl;
    for(int v : res ) cout << v << space ;
    cout <<endl;
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
