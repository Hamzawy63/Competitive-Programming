#include <iostream>
typedef long long int ll;
using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
int main() {
    int q ;
    cin >> q ;
    while(q-- ) {
        int n ;
        cin >> n ;
        string res = "" ;
        while(n >= 4)  {
            res += "11" ;
            n-=4 ;
        }
        if(n == 2 ) res += '1' ;
        else if(n==3) {res = '7' + res ;}
        else if (n ==1 ) {
            res = res.substr(0, res.size()-1);
            res = '7' + res  ;
        }
        cout << res  << endl ;
    }
    return 0;
}
