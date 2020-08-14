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
 
int n, q;
ll fen[2 * 100000 + 3];
 
void build() {
    for (int i = 0; i <= n; i++) fen[i] = 0;
}
 
ll sum(int r) {
    ll ans = 0;
    for (; r > 0; r -= (r & (-r))) ans += fen[r];
    return ans;
}
 
ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
 
void update(int idx, int delta) {
    for (; idx <= n; idx += (idx & (-idx))) fen[idx] += delta;
}
 
void range_update(int l, int r, int delta) {
    update(l, delta);
    if (r < n) update(r + 1, -delta);
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> q;
    vi ar(n + 1);
    build();
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        range_update(i, i, ar[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            range_update(a, b, c);
        } else {
            int a;
            cin >> a;
            cout << sum(a) << endl;
        }
 
    }
 
 
    return 0;
}