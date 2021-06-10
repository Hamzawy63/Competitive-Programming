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
#define MOD (int)(998244353 )
#define vi vector<int>
#define N (int)(1e7)
#define _DEBUG
using namespace std;
 
ll memo[2009][2009];
void ncr(int n , int r) {
    memo[0][0] = 1 ;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0  ; j<= i ; j++) {
            if(j == 0 ) memo[i][j] = 1 ;
            else if(j ==1 ) memo[i][j] = i ;
            else memo[i][j] = (memo[i-1][j] + memo[i-1][j-1])%MOD ;
        }
    }
}
 
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    IO;
    ncr(2000 , 2000) ;
    int n , m , k ;
    cin >> n >> m >> k ;
    ll res = (memo[n-1][k] * m)%MOD ;
 
    for(int i = 0 ; i <k  ; i++) {
        res  = (res * (m-1))%MOD ;
    }
    cout << res << endl;
 
 
 
    return 0;
}
