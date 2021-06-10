#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
 
int one(int &x) {
    if (x > 0) {
        x--;
        return 1;
    }
    return 0;
}
 
int two(int &x, int &y) {
    if (x > 0 && y > 0) {
        x--;
        y--;
        return 1;
    }
    return 0;
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, x, y;
        cin >> n >> x >> y;
        int worst = min(x + y - 1, n);
        int xl = max(0, min(x - 1, n - y - 1));
        int xr = max(0, min(y - 1, n - x - 1));
        int rasen = min(x - 1 - xl, y - 1 - xr);
        int best = x + y - 1 - xl - xr - max(0, rasen);
        cout << best << space << worst << endl ;
    }
 
    return 0;
}
