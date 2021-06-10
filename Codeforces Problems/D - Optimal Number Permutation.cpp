#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const vector<int> dy = {0, 0, 1, 0, -1, 1, -1, 1, -1};
 
void solve() {
    int n;
    cin >> n;
    vector<int> res(2 * n , -1 );
    int nxt = 0;
    for (int i = 1; i <= n; i += 2) {
        res[nxt] = i;
        res[nxt + (n - i)] = i;
        nxt++;
    }
    nxt = n ;
    for (int i = 2; i <= n; i += 2) {
        res[nxt] = i;
        res[nxt + (n - i)] = i;
        nxt++;
    }
    for (auto v : res) {
        if (v == -1)cout << n << space;
        else cout << v << space ;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
    //  freopen("output.txt", "w", stdout);
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
