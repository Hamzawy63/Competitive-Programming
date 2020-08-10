#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main() {
    string s;
    cin >> s ;
    char last ;
    int rep = 0 ;
    int ans = 0;
    for(auto c : s) {
        if(c == last) rep++ ;
        else {
            rep = 1 ;
            last=c ;
        }
        ans = max(ans , rep) ;
    }
    cout << ans << endl;
}
