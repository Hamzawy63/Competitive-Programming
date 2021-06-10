#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
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
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
 
//if (n > 1)
//cout << "Ashishgup" << endl;
//else
//cout << "FastestFinger" << endl;
void solve() {
    int n;
    cin >> n;
    if (n % 2 == 1) {
        if (n > 1)
            cout << "Ashishgup" << endl;
        else
            cout << "FastestFinger" << endl;
    } else {
        if(n == 2  )    cout << "Ashishgup" << endl;
        else if (n % 4 != 0) {
            bool ok = true;
            for (int i = 3; (ok) && i <= sqrt(n); i++) {
                if (n % i == 0 ) ok = false;
            }
            if (ok) cout << "FastestFinger" << endl;
            else cout << "Ashishgup" << endl;
        } else {
            while (n % 2 == 0)n /= 2;
            if (n == 1) cout << "FastestFinger" << endl;
            else cout << "Ashishgup" << endl;
        }
    }
 
}
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
