#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
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
    IO;
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        string even, odd;
        for (int i = 0; i < (int) s.size(); i++) {
            if ((s[i] - '0') % 2 == 0) even += s[i];
            else odd += s[i];
        }
        string res = "";
        int l0 = 0, l1 = 0;
        while (l1 < (int) odd.size() && l0 < even.size()) {
            if (even[l0] < odd[l1]) {
                res += even[l0++];
            } else
                res += odd[l1++];
        }
        while (l1 < (int) odd.size()) res += odd[l1++];
        while (l0 < (int) even.size()) res += even[l0++];
        cout << res << endl;
    }
 
    return 0;
}
