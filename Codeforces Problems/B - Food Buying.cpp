#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
int main() {
    IO;
    int q;
    cin >> q ;
    while(q-- ) {
        int n  ;
        cin >> n ;
        ll cost = 0 ;
        while(n/10 != 0){
            int ten = (int)pow(10 , (int)log10(n)) ;
            n-= ten ;
            cost += ten ;
            n+= (ten / 10)  ;
        }
        cout << cost + n << endl ;
 
    }
}
