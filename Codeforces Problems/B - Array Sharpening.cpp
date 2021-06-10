//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
typedef long long int ll;
using namespace std;
int main() {
    IO;
    int q ;
    cin >> q ;
    while(q-- ) {
        bool ok = true ;
        int n ;
        cin  >> n ;
        vector<int> a ;
        for(int i = 0 ; i < n ; i++) {
            int t;
            cin >> t ;
            a.push_back( t) ;
 
        }
        for(int i = 0 ; i <  (n/2 + n%2); i++ ){
            if(a[i] < i || a[n-i -1] < i){
                ok = false ;
                break ;
            }else {
               if(n%2 == 0 && i == n/2 - 1 ) {
                   if(a[i] == a[n-i-1] && a[i] == i )  {
                       ok = false ;
                       break ;
                   }
               }
            }
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl ;
 
 
 
    }
 
 
 
}
