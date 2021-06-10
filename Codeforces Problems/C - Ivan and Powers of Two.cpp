#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD = 1e9+7;
const int N=1<<19;
const ll INF=1e9+10;
double EPS=1e-099;
int main() {
    IO;
    int n ;
    cin>>n ;
    vector<int>vec(n);
    map<int, int> mask;
    int last = 0;
    for(int i = 0 ; i< n ; i++){
        cin>>vec[i];
        mask[vec[i]]++;
        last =max(last,vec[i]);
    }
    for(int i = 0 ; i < n ; i++){
        int num = vec[i];
        while (mask[num]>=2){
            int add =mask[num] / 2;
            mask[num]%=2 ;
            mask[num+1] +=add ;
            num++;
        }
    }
 
    vector<int>keys;
    for(auto it : mask ){
        if(it.second==0)continue;
        assert(it.second==1);
        keys.push_back(it.first);
    }
    n = keys.size() ;
    int ans= 0;
    for(int i =1 ; i < n ; i++){
        ans+=keys[i]-keys[i-1] - 1 ;
    }
    ans+=keys[0] ;
    cout<<ans<<endl;
 
}
