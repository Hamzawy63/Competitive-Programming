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
    int n, m;
    ll k;
    cin >> n >> m;
    cin >> k;
    if (k - (n - 1) <= 0) {
        cout << k + 1 << space << 1 << endl;
        return;
    }
    k -= (n - 1);
    int rows = k / (m - 1);
    int cols = k % (m - 1);
 
    int nn = n - rows;
    if (cols == 0) {
        nn++ ;
        if(rows%2 == 0 ) {
            cout <<nn << space << 2  <<endl;
        }else {
            cout << nn <<space << m <<endl;
        }
        return ;
    }
    int mm;
    if (rows % 2 == 1) { // <<<
        mm = m - cols +  1 ;
    } else if (rows % 2 == 0) {
        mm = cols + 1;
 
    }
    cout << nn << space << mm << endl;
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}
