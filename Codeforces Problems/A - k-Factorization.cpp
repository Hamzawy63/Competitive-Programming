#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
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
 
///=========================================================================================================
 
void solve() {
    int n, k;
    cin >> n >> k;
    int nn = n ;
    vector<int> a;
    while (n % 2 == 0) {
        n /= 2;
        a.pb(2);
    }
    for (int i = 3; i <= (int)sqrt(n) ; i += 2) {
        if (n % i == 0) {
            while (n % i == 0) {
                a.pb(i);
                n /= i;
            }
        }
    }
    if ((int) a.size() < k-1 &&n!=1 || a.size()<k && n==1) cout << -1 << endl;
    else {
        int product = 1;
        for (int i = 0; i < k - 1; i++) {
            cout << a[i] << space;
            product *= a[i];
        }
        cout << nn / product << endl;
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
