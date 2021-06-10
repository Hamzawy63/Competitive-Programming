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
    IO ;
    int q;
    cin >> q;
    while (q--) {
        string s ;
        cin >> s ;
        vi f[26 + 2] ;
        for(int i = 0 ; i < (int)s.size() ; i++ ){
            f[s[i] - 'a'].push_back(i) ;
        }
        string ans = "" ;
        for(int i = 0 ; i < 26 ; i++ ){
            int m = (int)f[i].size() ;
            if(m > 0 && m%2 == 1 ) ans+= (char)('a' + i ) ;
            else {
                bool ok = true ;
                for(int j = 0 ; j < m ; j+=2) {
                    if(f[i][j+1] - f[i][j] != 1 )
                        ok = false ;
                }
                if(!ok ) ans += (char )('a' + i ) ;
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}
