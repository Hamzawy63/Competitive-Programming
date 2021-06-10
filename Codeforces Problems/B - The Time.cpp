#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const vector<int> dy = {0, 0, 1, 0, -1, 1, -1, 1, -1};
 
void solve() {
    string s;
    cin >> s; // 23:59
    int n;
    cin >> n;
    int hrs = (s[0] - '0') * 10 + (s[1] - '0') ;
     n += (s[3] - '0') * 10 + (s[4]-'0')  ;
     int minutes = 0 ;
    minutes = minutes + n % 60;
    //minutes %=60 ;
    hrs = hrs + (n / 60);
    hrs %= 24;
    string res = "";
    if (hrs / 10 == 0) res += '0';
    res += to_string(hrs);
    res += ':';
    if (minutes / 10 == 0) res += '0';
    res += to_string(minutes);
    cout << res << endl;
}
 
int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
