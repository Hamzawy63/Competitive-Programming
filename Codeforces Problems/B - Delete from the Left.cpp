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
#define ACCURATE cout << fixed << setprecision(20)
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
    string s , t ;
    cin >> s >> t ;
    int i = s.size() -1 ;
    int j  = t.size() -1 ;
    int res = s.size() + t.size();
    while(j>=0 && i >= 0){
        if(s[i] == t[j]) {
            res-=2 ;
            i-- , j-- ;
        }else break ;
    }
    cout << res ;
    return 0;
}
