#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;
 
 
/**Global stuff */
 
/**Global stuff */
 
int main() {
    int q;
    cin >> q;
    vector<int> a;
    vector<int> b;
    ll res = 0;
    int fire = 0  ;
    for(int k  = 0  ; k < q ; k++)  {
        int n;
        cin >> n;
        int bottom = (int) 1e9;
        int top = -1;
        int l = (int) 1e9 ;
        bool ok = false ;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if(t < l ) l = t ;
            else if( t > l ){
                ok =true ;
            }
            if (bottom > t) {
                bottom = t;
            }
            if (t > top) {
                top = t;
            }
        }
        if (ok) {
            res += (2*(q- fire ) -1) ;
            fire++ ;
        }else  {
            a.push_back(bottom) ;
            b.push_back(top) ;
        }
 
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < (int) a.size(); i++) {
        int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        res += (b.size() - idx);
    }
    cout << res << endl;
 
    return 0;
 
 
}
