#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N=1e5+10;
int dp[N][3][2];
bool dp_track[N][3][2];
int n ;
string str;
const int INF=1e8;
int  solve(int index , int par , int start ){
    if(index==n){
        if(par==0)
            return 0;
        else return INF;
    }
    if(index>n)return -1;
    if(dp[index][par][start]!=-1)return dp[index][par][start];
    int Npar =par+str[index]-'0';
    Npar%=3;
    if(start&&str[index]=='0'){
        dp_track[index][par][start]=false;
        return dp[index][par][start]=1+solve(index+1,par,start);
    }
    int a = 1+solve(index+1,par,start);
    int b =solve(index+1,Npar,false);
    if(a<b){
        dp_track[index][par][start]=false;
    }else{
        dp_track[index][par][start]=true;
    }
    return dp[index][par][start]=min(a,b);
}
void print_track(int index , int par , int start ){
    if(index==n)return;
    if(dp_track[index][par][start]){
        cout<<str[index];
        print_track(index+1,(par+str[index]-'0')%3,false);
        return;
    }
    print_track(index+1,par,start);
}
int main(){
    IO;
    cin>>str;
    n = str.size();
    memset(dp,-1,sizeof(dp));
    int ans= solve(0,0,1);
    if(ans>=INF){
        cout<<-1;
    }
    if(ans==n){
        bool can = false;
        for(int i =0;i<n;i++){
            if(str[i]=='0'){
                can=true;
                break;
            }
        }
        if(can)
        cout<<0<<endl;
        else
            cout<<-1<<endl;
        return 0;
    }
 
    print_track(0,0,1);
    return 0;
}
