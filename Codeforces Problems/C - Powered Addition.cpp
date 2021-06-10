#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vi l(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)l[i] = a[i];
            else l[i] = max(l[i - 1], a[i]);
        }
        int res = 0;
        for(int i = n -1 ; i> 0 ; i--) {
            if(a[i] < l[i-1]){
                ll target = a[i] ;
                int power = 0 ;
                while(target  < l[i-1]){
                    target += (ll)pow(2 , power++ ) ;
                }
                res = max(power , res ) ;
            }
        }
        cout << res << endl ;
 
 
 
    }
    return 0;
 
}
