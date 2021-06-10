#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
 
 
//**********************
ll fen[12][100 * 1000 + 2];
 
void build() {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j <= 100 * 1000; j++) {
            fen[i][j] = 0;
        }
    }
}
 
void add(ll delta, int n, int k) {
    for (; n <= 1000 * 100; n += n & (-n)) {
        fen[k][n] += delta;
    }
}
 
ll sum(int k, int r) {
    ll ans = 0;
    for (; r > 0; r -= (r & (-r))) {
        ans += fen[k][r];
    }
    return ans;
}
 
//*************************
int main() {
    build();
    int n, k;
    cin >> n >> k;
    k++;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(1, a[i], 1);
        for (int j = 1; j <= k; j++) {
            ll state = sum(j - 1, a[i] - 1);
            add(state, a[i], j);
        }
    }
    cout << sum(k, n) << endl;
    return 0;
}
