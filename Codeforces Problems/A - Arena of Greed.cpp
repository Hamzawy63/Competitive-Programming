#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define speed() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e18 + 18;
const int mxN = 2e5 + 5, MOD = 1e9 + 7;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll me = 0;
        int turn = 1;
 
        while (n) {
            if (n % 2 == 0) {
                if ((n / 2) % 2 == 0 && n != 4) {
                    me++;
                    n -= 2;
                } else {
                    if (turn) {
                        me += n / 2;
                        turn = 0;
                    } else turn = 1;
 
                    n /= 2;
                }
            } else {
                if (turn) {
                    me++;
                    turn = 0;
                } else turn = 1;
                n--;
            }
        }
        cout << me << endl;
    }
}
