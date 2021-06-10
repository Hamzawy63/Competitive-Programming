#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
 
//#define _DEBUG
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 2 ; i <= n ; i++) {
      if(n%i ==0 )   reverse(s.begin() , s.begin() + i) ;
    }
    cout << s << endl ;
    return 0;
}
