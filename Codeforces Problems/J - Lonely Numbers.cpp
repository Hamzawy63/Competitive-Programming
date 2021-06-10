#include <bits/stdc++.h>
 
using namespace std;
#define  IO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef long double ld;
const ll INF = 1e17;
const ll N = 6e5 + 100;
const int MOD = 1e9 + 7;
vector<int>sieve(1e6+5,-1);
 
 
int main(){
    vector<int>ans(1e6+5);
    ans[1]= 1 ;
    ans [2] = 2 ;
    unordered_set<int>last;
    last.insert(1);
    last.insert(2);
    vector<int>test;
    for(ll i = 2 ; i <=1e6 ; i++){
        if(sieve[i]==-1){
            test.push_back(i);
            for(ll j = i*i ; j<=1e6 ; j +=i){
                sieve[j]=i;
            }
        }
    }
 
 
    for(int i = 3 ; i<=1e6 ; i++ ){
        int sq = sqrt(i);
        if(sq*sq==i){
            last.erase(sq);
        }
        if(sieve[i]==-1)last.insert(i);
        ans[i]=last.size();
    }
 
    int t ;
    cin>>t;
    while (t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
}
