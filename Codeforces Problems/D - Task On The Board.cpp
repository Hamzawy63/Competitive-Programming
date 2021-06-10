 
#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define ff first
#define ss second
void solve() {
    string s ;
    cin >> s ;
    int f[26 + 3 ] ;
    int last_taken_char = 25 ;
    for(int i=0;i<26 ;i++) f[i] = 0;
 
    for(auto c : s){
        f[c - 'a']++;
    }
    int m ;
    cin >> m ;
    vi a(m) ;
    vector<char> res(m);
    for(int i=0;i<m;i++){
        cin >> a[i] ;
    }
    bool ok = true ;
    while(ok){
        ok = false ;
        int cnt = 0;
        vi indices ;
        for(int i =0 ; i < m ;i++){
            if(a[i] == 0 ) {
                ok = true;
                a[i] = -1 ;
                indices.push_back(i);
                cnt ++ ;
            }
        }
        if(ok){
            for(int i=last_taken_char;i>=0;i--){
                if(f[i] >= cnt ){
                    last_taken_char = i ;
                    f[i] = 0 ;
                    for(auto idx : indices){
                        res[idx] = (char)('a' + i);
                    }
                    break;
                }
            }
            for(int i=0;i<m;i++){
                if(a[i] > -1 ) {
                    for(auto idx : indices){
                        a[i] -= abs((i) - idx);
                    }
                }
            }
//            for(auto bb : a ) {
//                cerr << bb << space ;
//            }
//            cerr << endl;
        }
    }
    for(auto c : res) cout << c ;
    cout << endl;
 
 
 
}
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
