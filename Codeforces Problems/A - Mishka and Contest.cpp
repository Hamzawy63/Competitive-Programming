#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
 
//#define _DEBUG
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n , k ;
    cin >> n >> k  ;
    vector<int> a ;
    for(int i= 0 ; i < n ;i++) {
        int t;
        cin >> t;
        a.push_back(t) ;
    }
    int l = 0 , r  = n-1;
    bool ok = true;
    int res = 0 ;
    while(l<=r && ok) {
        if(a[l] <= k ) {
            res++ ;
            l++ ;
        }else if (a[r] <= k ) {
            r-- ;
            res ++ ;
        }else ok = false ;
    }
    cout << res <<endl;
    return 0;
}
