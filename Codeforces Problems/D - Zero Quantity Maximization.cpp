#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <unordered_map>
 
typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(12)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n ;
    cin >> n ;
    vector<int > a(n) ;
    vector<int > b(n) ;
    for(int i  = 0 ; i < n ; i++ ){
        cin >> a[i] ;
    }
 
    for(int i  = 0 ; i < n ; i++ ){
        cin >> b[i] ;
    }
   int org = 0 ; 
    map<pair<int , int > , int > mp ;
    for(int i = 0 ; i < n ; i ++) {
        if(a[i] ==0 && b[i] == 0 ) org++ ;
        else if(a[i] ==0  ) continue ; 
        else {
            int f  = -1 * a[i] / __gcd(a[i], b[i]) ;
            int s  = b[i] / __gcd(a[i], b[i]) ;
            if(mp.count(make_pair(f , s ))) mp[make_pair(f,s )] ++ ;
            else mp[make_pair(f ,s )] = 1 ;
        }
    }
    int res= 0  ;
    for(map<pair<int , int >  , int >::iterator it = mp.begin() ; it!=mp.end() ; it++) {
        res = max(res , it->second) ;
    }
    cout << res + org ;
    return 0;
}
