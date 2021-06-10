#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
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
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
///=========================================================================================================
ll ppow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
bool left(ll cur) {
    for(int i = 0 ; i <= 60 ; i++) {
        ll left = ppow(2,i) ;
        ll delta= ppow(2,i+1) ;
        // left + K * delta = cur
        if((cur - left)%delta == 0 ) {
            return ((cur-left)/delta)%2 == 0  ;
        }
    }
 
}
 
void solve() {
    // one test case
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll nn;
        cin >> nn;
        string s;
        cin >> s;
 
        int lvl  =0 ;
        for(int i = 0 ;i<=60 ;i++) {
            ll left = ppow(2,i) ;
            ll delta= ppow(2,i+1) ;
            // left + K * delta = cur
            if((nn - left)%delta == 0 ) {
                lvl = i ;
                break ;
            }
        }
        int upper_level = (int) log2(n + 1) - 1;
        ll cur = nn;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == 'U') {
                if (lvl != upper_level) {
                    if (left(cur))
                        cur += ppow(2, lvl);
                    else
                        cur -= ppow(2, lvl);
                    lvl++;
                }
            } else if (s[i] == 'R') {
                if (lvl != 0) {
                    cur += ppow(2, lvl - 1);
                    lvl--;
                }
            } else if (s[i] == 'L') {
                if (lvl != 0) {
                    cur -= ppow(2, lvl - 1);
                    lvl--;
                }
            }
        }
        cout << cur << endl;
    }
 
}
 
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
