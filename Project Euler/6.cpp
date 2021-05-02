#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n = 100 ; 
    ll sum = n*(n+1)/2 ; 
    ll ans = sum * sum  ;
    for(int i=1;i<=100;i++){
        ans -= i*i ;
    } 
    cout << ans << endl; 
}