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
    int q ;
    cin >> q;
    while(q -- ) {
        int n ;
        cin >> n ;
        bool ok = true ;
        int f = 0 , s = 0 ;
        for(int i =0  ;i < n ;i++ ){
            int a , b ;
            cin >>a >> b;
            if(b > a ) ok = false;
            if(b > s && a -f <  b - s  ) ok = false ;
            else if(a < f  || b < s ) ok =false ;
 
 
            f = a ;
            s = b ;
        }
        if(ok ) cout << "YES" ;
        else cout << "NO" ;
        cout << endl ;
 
    }
 
    return 0;
 
}
