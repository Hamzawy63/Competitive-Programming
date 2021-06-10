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
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        bool ok = true, pos = false, neg = false;
        for (int i = 0; ok && i < n; i++) {
            if (a[i] > b[i]) {
                if (!neg) ok = false;
            } else if (b[i] > a[i])
                if (!pos) ok = false;
 
            if(a[i] == 1 ) pos = 1 ;
            if(a[i] == -1 ) neg = 1 ;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
 
    }
    return 0;
}
