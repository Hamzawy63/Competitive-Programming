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
    int k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;
    int n = (int) s.size();
    if (b * k < n || a * k > n) {
        cout << "No solution" << endl;
        return 0;
    }
    vector<int> res;
    int l = a, r = b;
    int mid ;
    while(k>1) {
        while (l <=r) {
            int mid = l + (r - l) / 2;
            if (b * (k-1) < (n - mid))
                l = mid + 1 ;
            else if( a*(k-1) > (n - mid) )
                r = mid -1 ;
            else {
                res.push_back(mid);
                n -= mid;
                k--;
                break ;
            }
        }
    }
    int st = 0 ;
    for(int i =0  ; i< res.size() ; i++) {
        for(int j = 0 ; j< res[i]  ; j++) cout << s[st++] ;
        cout << endl ;
    }
    while(st < s.size()) cout << s[st++] ;
    cout << endl;
    return 0;
 
 
}
