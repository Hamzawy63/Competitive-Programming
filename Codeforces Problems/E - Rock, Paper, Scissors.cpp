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
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
#define mp make_pair
#define ar array
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
const int maxN = 3e5 + 3;
const int inf = 2e9;
 
 
int solve(int p1, int p2, int r1, int r2, int s1, int s2, int i) {
    ll ans = 0;
    int t1 = 0, t2 = 0, t3 = 0;
    if (i & 1) {
        t1 = min(r2, s1);
    }
    if (i & 2) {
        t2 = min(s2, p1);
    }
    if (i & 4) {
        t3 = min(p2, r1);
    }
    r2 -= t1;
    s1 -= t1;
    s2 -= t2;
    p1 -= t2;
    p2 -= t3;
    r1 -= t3;
 
    t1 = min(r1, r2);
    r1 -= t1;
    r2 -= t1;
 
    t1 = min(s1, s2);
    s1 -= t1;
    s2 -= t1;
 
    t1 = min(p1, p2);
    p1 -= t1;
    p2 -= t1;
 
 
    t1 = min(r2, s1);
 
 
    t2 = min(s2, p1);
 
 
    t3 = min(p2, r1);
 
    r2 -= t1;
    s1 -= t1;
    s2 -= t2;
    p1 -= t2;
    p2 -= t3;
    r1 -= t3;
 
 
  //  cerr << p1 + p2 + s1 + s2 + r1 + r2 << endl;
    return (p1 + p2 + s1 + s2 + r1 + r2) / 2;
}
 
 
void solve() {
    // r , s , p
    int n;
    cin >> n;
    int r1, s1, p1;
    int r2, s2, p2;
    cin >> r1 >> s1 >> p1 >> r2 >> s2 >> p2;
    int lose = n;
    for (int i = 0; i < (1 << 3); i++) {
        int t = solve(r1, r2, s1, s2, p1, p2, i);
        lose = min(lose, t);
    }
 
    cout << lose << space << min(r1, s2) + min(s1, p2) + min(p1, r2) << endl;
 
 
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
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
