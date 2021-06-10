#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll INF = 1e16;
int main(){
    int n , m ;
    cin>>n>>m ;
    string str;
    cin>>str;
    string ans (n,'?');
    for(int i = 0 ; i < n  ; i  ++){
        int disa = min ( abs ('a' -str[i] ) , m)  ;
        int disb = min ( abs ('z' -str[i] ) , m)  ;
        if(disa > disb ){
                ans[i] = str[i] - disa;
                m-=disa;
        } else{
                ans[i] = str[i] + disb;
                m-=disb;
        }
    }
    if(m){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}
