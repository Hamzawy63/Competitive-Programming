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
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int table[(int)log2(n) + 1][n] ;
    for(int i=0;i<=log2(n);i++){
        for(int j=0;j<n;j++){
            if(i == 0 ) {
                table[i][j] = a[j] ;
            }else {
                table[i][j] = min(table[i-1][j] , table[i-1][j + (1 << (i-1))]) ;
            }
        }
    }
    int q;
    cin >> q ;
    while(q-- ) {
        int l , r ;
        cin >> l >>r ;
        int len = r- l +1 ;
        int lg = log2(len) ;
        cout << min(table[lg][l] , table[lg][r - (1 << lg) + 1 ]) << endl;
    }
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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}