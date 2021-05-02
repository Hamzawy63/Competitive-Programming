#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    vector<int> primes ; 
    int n = 200000 ; 
    vector<int> s(n+1,1) ; 
    s[0] = s[1] = 0 ; 
    for(int i=2;i<=n;i++){
        if(!s[i]) continue ; 
        if(s[i]) primes.push_back(i) ; 
        for(int j=i+i;j<n;j+=i){
            s[j] = 0; 
        }
    }
    cout << primes[10000] << endl; 
}
