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
void solve() {
    int n ;
    cin >> n ;
    vector<pair<int , pair<int , int >>> a(2*n) ;
    for(int i=0;i<2*n;i++){
        int t ;
        cin >> t ;
        a[i] = {t%2 , {t , i }};
    }
    sort(a.begin() , a.end()) ;
    int k = 0 ;
    for(int i=0; i<(2*n - 1 ) && k < n-1 ;){
        if(a[i].first != a[i+1].first) i++ ;
        else{
            k++ ;
            cout << a[i].second.second + 1  << space << a[i+1].second.second + 1  << endl;
            i+=2 ;
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
