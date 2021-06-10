#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int MOD=1e9+7;
int main(){
    IO;
    int n , p , q ;
    cin>>n>>p>>q;
    string str;
    cin>>str;
    for(int i = 0 ;i<= n ; i++){
        int a = i  * p ;
        int index = 0;
 
        if((n-a)%q==0 && (n-a)>=0  ){
            // i of p
            // (n-a)/q  of q
           cout<<i+(n-a)/q<<endl;
            for(int j = 0 ; j< i ; j++){
                cout<<str.substr(index, p)<<endl;
                index +=p;
            }
 
            int last = (n-a)/q;
            for(int j = 0 ; j< last ; j++){
                cout<<str.substr(index, q)<<endl;
                index +=q;
            }
 
            return 0;
        }
    }
    cout<<-1<<endl;
 
}
