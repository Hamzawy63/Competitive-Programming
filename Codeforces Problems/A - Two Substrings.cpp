#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;
 
 
/**Global stuff */ ;
ll dp[2009][2009];
vi arr[2009];
 
/**Global stuff */
 
int main() {
    string s ;
    cin >> s ;
    vector<int> ab ;
    vector<int> ba ;
    for(int i = 0  ; i <(int)s.size() -1 ; i++){
        if(s[i] == 'A'  && s[i+1] == 'B')
            ab.push_back(i) ;
        if(s[i+1] == 'A'  && s[i] == 'B')
            ba.push_back(i) ;
    }
    string ok = "NO" ;
    for(auto i : ab){
        int idx = upper_bound(ba.begin()  , ba.end() , i + 1) - ba.begin()  ;
        if(idx != (int)ba.size()) ok = "YES" ;
    }
    for(auto i : ba){
        int idx = upper_bound(ab.begin()  , ab.end() , i + 1) - ab.begin()  ;
        if(idx != (int)ab.size()) ok = "YES" ;
    }
    cout << ok << endl;
    return 0;
}
