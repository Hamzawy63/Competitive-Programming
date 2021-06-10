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
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
string s;
int n;
const string target = "abacaba";
 
bool check(int idx , string &s ) {
    if (idx + 6 >= n) return false;
    bool ok = true;
    for (int i = 0; i < 7; i++) {
        ok &= (target[i] == s[idx + i]);
    }
    return ok;
}
 
void solve() {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += check(i,s);
    }
    if (cnt == 1) {
        cout << "YES" << endl;
        for (auto c : s) {
            if (c == '?') c = 'z';
            cout << c;
        }
        cout << endl;
 
    } else if (cnt > 1)
        cout << "NO" << endl;
    else {
        for(int i=0;i+6<n;i++){
            string t = s ;
            bool ok = true ;
            for(int j = 0 ; j < 7 ; j++ ){
                ok &= ((t[i+j] == target[j]) || (t[i+j] == '?') ) ;
                if(t[i+j] == '?') t[i+j] = target[j] ;
            }
            if(ok) {
                for(int j=0;j<n;j++) if(i != j )
                    ok &= (!check(j,t)) ;
            }
            if(ok) {
                cout << "YES" << endl;
                for(auto c : t ) cout << ((c == '?') ? 'z' : c) ;
                cout << endl;
                return ;
            }
        }
        cout << "NO" << endl;
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
        //   cout << "Case #" << i << ": ";
        solve();
    }
}
