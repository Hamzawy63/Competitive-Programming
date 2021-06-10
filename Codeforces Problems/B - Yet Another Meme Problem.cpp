#include <iostream>
#include<bits/stdc++.h>
typedef long long int ll ;
 
using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define space " "
 
int main() {
    int q ;
    cin >> q ;
    while(q--) {
       ll a ,b  ;
       cin  >> a >> b ;
       ll res = 0 ;
       for(ll i = 9 ; i<9e9 ; i = i*10+9){
           if(b - i >= 0 ) res ++ ;
       }
       cout << res * a << endl ;
 
    }
 
 
    return 0;
}
