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
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 10
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e7)
#define _DEBUG
using namespace std;
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    IO;
    int q;
    cin >> q;
    while (q--) {
        ll n, m;
        cin >> n >> m;
        ll z = (n - m ) / (m+1 ) ;
 
        ll mod =(n - m ) % (m+1 )  ;
        ll s1 = (m+1-mod)*z*(z+1) /2 ;
        ll s2 = (z+1)*(z+2)/2 * mod ;
        cout << n*(n+1)/2 - s2 - s1 << endl ;
    }
 
 
    return 0;
}
