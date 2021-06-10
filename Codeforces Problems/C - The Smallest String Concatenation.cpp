#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
struct myclass {
    bool operator() (string a,string b ) {
        string string1 = a+b,string2 = b + a;
        return string1 < string2;
    }
};
int main() {
    IO;
    int n ;
    cin>>n ;
    vector<string>vec(n);
    for(int i = 0; i < n ; i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end(),myclass());
    for(string str : vec)cout<<str;
 
    return 0;
}
