#include <bits/stdc++.h>
 
typedef long long ll;
typedef long double ld;
using namespace std;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
int main() {
    IO;
    int n;
    cin >> n;
    map<int , int>m ;
    int ans = 0 ;
    for(int i = 0 ;i < n; i ++){
        int num ;
        cin>>num ;
        m[num]++;
        ans = max(ans,m[num]);
    }



