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
vector<int> a(105);
int n ;
int dp[105][60][60][2] ;
int solve(int i, int even, int odd, int last) {
    if (i == (int)n) return 0;
    if(last!=-1&&dp[i][even][odd][last] != -1)
        return dp[i][even][odd][last] ;
    int res ;
    if (a[i] == -1) {
        int f = MAX, s = MAX;
        if (even > 0) f = (last == 1)  +  solve(i + 1, even - 1, odd, 0);
        if (odd > 0) s =  (last == 0)  +  solve(i + 1, even, odd - 1, 1);
        res= min(f, s);
    } else {
        res = (a[i] % 2 != last && i!=0 ) + solve(i + 1, even, odd, a[i] % 2);
    }
//    for(int j = 0  ; j < i ; j++) cout << space ;
//    cout << "for i = " << i << " , We have " << res << " as a cost " << endl ;
    dp[i][even][odd][last] = res ;
    return res ;
 
}
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
#endif
    IO;
    cin >> n;
    int odd = n / 2 + n % 2;
    int even = n / 2;
    for(int i = 0 ; i <= n ; i ++) {
        for(int j = 0 ;  j<= (n+1)/2 ;  j++) {
            for(int k = 0 ; k <=(n+1)/2 ; k ++ ){
                for(int l = 0 ; l <2 ; l ++) {
                    dp[i][j][k][l]  = -1 ;
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0 ) a[i] = -1 ;
        a[i] %= 2 ;
        if (a[i] != -1) {
            if (a[i] % 2) odd--;
            else even--;
        }
 
    }
    cout << solve(0 , even , odd , -1) ;
    return 0;
}
