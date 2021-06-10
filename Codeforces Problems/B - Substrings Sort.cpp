#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
 
typedef long long int ll;
using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
 
bool compare(string &s1,string &s2)
{
    return s1.size() < s2.size();
}
 
 
 
int main() {
    IO;
    int n;
    cin >> n;
    string s[n+E] ;
    for(int i =0 ; i < n ;i++) {
        string in ;
        cin >> in ;
        s[i] = in ;
    }
    int ok = true ;
    for(int i = 0 ; i< n ; i++ ) {
        for(int j = 0 ; j< n ; ++j ) {
            if( s[i].size() <= s[j].size() && s[j].find(s[i]) == string::npos){
               // cout << "bad with " << s[j] << " and   " << s[i] << endl;
                ok = false ;break;
            }
 
        }
        if(!ok ) break ;
    }
    if(ok ) {
        cout << "YES"  << endl;
        sort(s , s+ n , compare) ;
        for(int i=  0; i < n ; ++i) cout << s[i] << endl ;
    }
    else cout << "NO" << endl ;
 
 
 
 
    return 0;
 
}
