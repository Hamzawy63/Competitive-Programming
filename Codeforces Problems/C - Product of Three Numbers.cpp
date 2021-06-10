#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define space " "
 
int main() {
    int n ;
    cin >> n ;
    double res= 0  ;
 
    for(int i = 1 ; i <= n ; i++) {
        res += 1/(double)i ;
    }
    cout << fixed << setprecision(20);
    cout << res <<endl ;
    return 0;
}
