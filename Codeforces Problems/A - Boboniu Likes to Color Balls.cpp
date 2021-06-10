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
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = 1000000007;
 
void solve() {
    ll r, g, b, w;
    cin >> r >> g >> b >> w;
    ll ev = 0, od = 0;
    if (r % 2 == 0) ev++; else od++;
    if (g % 2 == 0) ev++; else od++;
    if (b % 2 == 0) ev++; else od++;
    if (w % 2 == 0) ev++; else od++;
 
    if (od <= 1) cout << "Yes" << endl;
    else {
        if (r == 0 || g == 0 || b == 0) {
            cout << "No" << endl;
            return ;
        }
        if(ev == 1 ) {
            cout << "Yes" <<endl;
            return ;
        }else {
            int least = min(r , min(g,b)) ;
            r -=least ;
            g-=least ;
            b-=least ;
            w += 3 * least ;
            ev = 0, od = 0;
            if (r % 2 == 0) ev++; else od++;
            if (g % 2 == 0) ev++; else od++;
            if (b % 2 == 0) ev++; else od++;
            if (w % 2 == 0) ev++; else od++;
            if(od <= 1 ) cout << "Yes" <<endl;
            else cout << "No"<<endl;
        }
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
