#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
const double inf = 2e18;
#define EPS  0.0000000001
 
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<char> nxt(n);
    nxt[n - 1] = '*';
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1]) nxt[i] = nxt[i + 1];
        else nxt[i] = s[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
      if(s[i] == s[i+1]) {
          char bad = '*' ;
          if(i+2 < n ) bad = s[i+2] ;
          for(char c = 'a' ; c <='z';c++){
              if(c != s[i] && c != bad  ){
                  s[i+1] =c ;
                  break;
              }
          }
      }
    }
    cout << s << endl;
}
 
int main() {
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }
 
 
}
