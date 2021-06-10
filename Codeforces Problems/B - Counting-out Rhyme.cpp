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
void solve() {
    // one test case
    int n, k;
    cin >> n >> k;
    vi a(n), ind(n);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < n; i++) ind[i] = i;
    int leader = 0;
    for (int i = 0; i < k; i++) {
        a[i] %= (n-i) ;
        for(int j = leader, cnt = 0 ; cnt <= a[i] ;j = ((j+1)%(n))) {
            if(ind[j] == -1 ) continue;
            if(cnt == a[i] ){
                cout << ind[j] +1<< space ;
                ind[j] = -1 ;
                for(int kk = j ; kk < n ;kk=(kk+1)%n){
                    if(ind[kk] != -1 ) {
                        leader = kk ;
                        break;
                    }
                }
            }
            cnt ++ ;
        }
    }
    cout << endl;
 
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
