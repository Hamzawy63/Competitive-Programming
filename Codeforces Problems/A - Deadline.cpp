#include <iostream>
#include<bits/stdc++.h>
typedef long long int ll ;
#define E 10
#define space " "
using namespace std;
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
void debug() {
    cout << "Here we are " << endl;
}
 
int main() {
    int q ;
    cin >> q ;
    while(q-- ) {
        int n ,x ;
        cin >> n >> x ;
        string s ;
        cin >> s ;
        int ones = 0 , zeros = 0 ;
        int a[n+E] ;
        for(int i = 0 ; i< n ; i++)  {
            if(s[i] == '0') zeros ++ ;
            else ones ++ ;
            a[i] = zeros - ones ;
        }
        ll res = 0 ;
        int diff = zeros - ones ;
        if(x == 0 ) res += 1 ;
        for(int i = 0 ; i < n ; i++) {
            if(diff != 0 && (x - a[i])%diff == 0 ){
                if((x - a[i]) /diff >= 0 ) res ++;
            }else if (diff == 0) {
               if(a[i] == x ) {
                   res = -1 ;
                   break ;
               }
            }
        }
 
        cout << res << endl ;
    }
    return 0 ;
}
