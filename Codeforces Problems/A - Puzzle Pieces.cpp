#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
void solve() {
    int n , m ;
    cin >> n >>m ;
    if(n == 1 || m == 1 ) cout << "YES" << endl;
    else if( n == 2 && m == 2 ) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    return 0;
}
