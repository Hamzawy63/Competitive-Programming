#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    int n, q;
    cin >> n >> q;
 
    vi pre(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        pre[i] = t ^ pre[i - 1];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pre[b] ^ pre[a -1 ]) << endl;
    }
 
 
}