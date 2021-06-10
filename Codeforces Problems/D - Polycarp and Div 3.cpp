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
 
vector<vector<int >> mat_mul(vector<vector<int>> a, vector<vector<int>> b) {
    // a = n*n , b = n*n :)
    int N = a.size();
    vector<vector<int>> ans(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ans[i][j] += a[i][k] + a[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}
 
//  #define _DEBUG
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
 
    string s;
    cin >> s;
    int n = s.size();
    vector<int > a ;
    for(int i = 0 ; i < n ; i ++ ) a.push_back((s[i] - '0') % 3) ;
    int sum = 0 ;
    for (int i = 0; i < n;) {
        if(a[i] == 0 ) {
            sum++ ;
            i++;
        }else if(i<n-1 &&(a[i] + a[i+1]) %3 == 0){
            sum++ ; i+=2 ;
        }else if(i < n-2 && a[i+1]!= 0 && a[i+2] != 0){
            i+=3 ;
            sum+= 1 ;
        }else i++ ;
    }
    cout << sum << endl ;
    return 0;
}
