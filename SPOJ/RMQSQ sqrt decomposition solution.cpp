#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "
const int maxN = 200000 + 2;

int main() {
    int n, q;
    cin >> n ;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    int block_size = (int)sqrt(n);
    int number_of_blocks = n / block_size;
    if(n % block_size != 0 ) number_of_blocks++ ;
    vector<int> blk;
    for (int i = 0; i < number_of_blocks; i++) {
        int res = INT_MAX;
        for (int j = block_size * i; j < min(n, (i + 1) * block_size); j++) {
            res = min(res, a[j]);
        }
        blk.push_back(res);
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int bl1 = l / block_size;
        int bl2 = r / block_size;
        int res = INT_MAX;
        if (bl1 == bl2) {
            for (int i = l; i <= r; i++) res = min(res, a[i]);
            cout << res << endl;
            continue;
        }
        for (int i = l; i < (bl1 + 1) * block_size; i++) {
            res = min(res, a[i]);
        }
        for (int i = bl1 + 1; i < bl2; i++) {
            res = min(res, blk[i]);
        }
        for (int i = bl2 * block_size; i <= r; i++) {
            res = min(res, a[i]);
        }
        cout << res << endl;
    }

}