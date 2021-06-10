#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
int main(){
    int n ;
    cin>>n ;
    int arr[n+2];
    for(int i =0;i<n;i++)cin>>arr[i];
    map<int , int >m ;
    vector<pair<int, int>>ans;
    int l = 0 ;
 
    for(int i = 0 ;i<n;i++){
        if(m.count(arr[i])){
            ans.push_back({l,i});
            l=i+1;
            m.clear();
        }else{
            m[arr[i]]=i;
        }
    }
    if(ans.size()==0){
        cout<<-1;
        return 0;
    }
    cout<<ans.size()<<endl;
    ans.back().second=n-1;
    for(auto it : ans){
 
        cout<<it.first+1<<" "<<it.second+1<<endl;
    }
}
