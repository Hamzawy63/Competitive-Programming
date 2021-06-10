#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define speed() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e18 + 18;
const int mxN = 2e5 + 5, MOD = 1e9 + 7;
 
int b1,b2,b3,b4;
 
void solve() {
 
    cin >> b1 >> b2 >> b3 >> b4;
    if (b1 && b2) {
        b3 = 1; b4= 1; int temp = min(b1,b2);
        b1-=temp; b2-=temp;
    }
    if (b1 && b1 != 1) {
        if (b1%2) {
            b4 = 1;
            b1 = 1;
        } else {
            b4= 1;
            b1 = 0;
        }
    }
    if (b2 && b2 != 1) {
        if (b2%2) {
            b3 = 1;
            b2 = 1;
        } else {
            b3= 1;
            b2 = 0;
        }
    }
    if (b1 || (b2 && b4)) {
        cout << "Ya ";
    } else {
        cout << "Tidak ";
    }
    if (b2 || (b1&&b3)) {
        cout << "Ya ";
    } else {
        cout << "Tidak ";
    }
    if (b3 && !b1 && !b2) {
        cout << "Ya ";
    } else {
        cout << "Tidak ";
    }
    if (b4 && !b1 && !b2) {
        cout << "Ya" << endll;
    } else {
        cout << "Tidak" << endll;
    }
 
}
 
int main() {
    speed()
    int t; cin >> t;
    while (t--) {
        solve();
    }
 
}
