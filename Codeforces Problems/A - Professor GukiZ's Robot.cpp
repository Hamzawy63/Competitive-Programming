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
void solve() {
    int x0 , x1 , y0 , y1 ;
    cin >> x0 >> y0 >> x1 >> y1 ;
    int num  = min ( abs ( x0 - x1 )  ,abs (y0-y1 ));
    int ans = num + (abs ( x0 - x1 )- num  ) + (abs (y0-y1 )-num );
    cout << ans<<endl;
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
