#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <map>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
 
void solve() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        string s = "";
        if (b != 0) {
            if (a * c == 0) b++;
            for (int i = 0; i < b; i++) s += '0' + (i % 2);
            if (c > 0) {
                if (s.back() == '0')
                    for (int i = 0; i < (int) s.size(); i++) if (s[i] == '0') s[i] = '1'; else s[i] = '0';
                for (int i = 0; i < c; i++) s += '1';
                if (a > 0)
                    for (int i = 0; i <= a; i++) s += '0';
            } else {
                if (s.back() == '1')
                    for (int i = 0; i < (int) s.size(); i++) if (s[i] == '0') s[i] = '1'; else s[i] = '0';
                for (int i = 0; i < a; i++) s += '0';
 
            }
        } else {
            if (a > 0) for (int i = 0; i < a + 1; i++) s += '0';
            if (c > 0) for (int i = 0; i < c + 1; i++) s += '1';
        }
        cout << s << endl;
    }
 
}
 
//cout << "Case #" << i << ": ";
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
