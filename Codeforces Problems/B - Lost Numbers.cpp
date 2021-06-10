#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
string str1, str2;
const int N = 5e5+5;
 
int query(int a , int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int dif(int num , pair<int, int > k ){
    if(num==k.first)return k.second;
    return k.first;
}
int same (pair<int,int> a , pair<int, int> b){
    if(a.first==b.first)return a.first;
    if(a.first==b.second)return a.first;
    return a.second;
}
int main(){
 
    IO;
    int n = 6 ;
    int arr[]={4 , 8 , 15 , 16 , 23 ,42 };
    map<int , pair<int, int>>lastDie;
    for(int i =0; i< 6 ; i++){
        for(int j = i +1 ; j <n ; j++){
            int d = arr[i]*arr[j];
            lastDie[d]={arr[i],arr[j]};
        }
    }
    pair<int, int>f1 =lastDie[query(1,2)];
    pair<int, int>f2 =lastDie[query(2,3)];
    int ans[8];
    ans[1]=same(f1,f2);
    ans[0]=dif(ans[1],f1);
    ans[2]=dif(ans[1],f2);
 
    f1 =lastDie[query(4,5)];
    f2 =lastDie[query(5,6)];
    ans[4]=same(f1,f2);
    ans[3]=dif(ans[4],f1);
    ans[5]=dif(ans[4],f2);
    cout<<"! ";
    for(int i = 0 ; i< 6 ; i++){
        cout<<ans[i]<<" ";
    }
}
/*
 32
 120
 368
 966
 */
