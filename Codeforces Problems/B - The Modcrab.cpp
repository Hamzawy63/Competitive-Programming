#include <bits/stdc++.h>
 
typedef long long ll;
typedef long double ld;
using namespace std;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
int main() {
    IO;
    int h1 , a1 ,c1 ;
    int h2 , a2 ;
    cin>>h1>>a1>>c1>>h2>>a2;
    vector<string >ans;
    while (h2>0){
        if(h2-a1<=0){
            ans.push_back("STRIKE");
            break;
        }
        if (h1-a2<=0){
            h1+=c1;
            ans.push_back("HEAL");
            h1-=a2;
            continue;
        }
        h2-=a1;
        h1-=a2;
        ans.push_back("STRIKE");
    }
    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it<<'\n';
    }
    return 0;
}
