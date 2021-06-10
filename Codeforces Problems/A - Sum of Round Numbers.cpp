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
    int q ;
    cin >> q ;
    while(q--) {
        int n ;
        cin >> n ;
        vi res ;
        for(int i =  4 ; i >=0  ; i-- ) {
            for(int j = 9 ; j > 0  ; j-- ) {
                int target = j * (int)pow(10 , i) ;
                if(target <= n ) {
                    n-= target ;res.push_back(target) ;
                }
            }
        }
        cout << (int)res.size() << endl; ;
        for(auto  i : res ) cout << i << space ;
        cout << endl;
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
