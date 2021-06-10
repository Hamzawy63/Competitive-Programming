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
    int n, m;
    cin >> n >> m;
    bool ok = true;
    vii a(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if ((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == m - 1)) {
                if (a[i][j] > 2) ok = false;
                else a[i][j] = 2;
            } else if (i == 0 || j == 0 || i == n-1 || j == m-1 ) {
                if (a[i][j] > 3) ok = false;
                else a[i][j] = 3;
            } else {
                if (a[i][j] > 4) ok = false;
                else a[i][j] = 4;
            }
        }
    }
    if(!ok) {
        cout << "NO" << endl;
    }else {
        cout << "YES" <<endl;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                cout << a[i][j] << space ;
            }
            cout << endl;
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
