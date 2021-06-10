#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
string str1, str2;
const int N = 5e5+5;
int parent[N];
int getParent(int a){
    if(parent[a]==a)return a;
    return parent[a]=getParent(parent[a]);
}
void  makeParent(int a , int b ){
    a =getParent(a);
    b=getParent(b);
    parent[a]=b;
}
int main(){
       IO;
       int n , m ;
       cin>>n>>m ;
       for(int  i= 0 ; i < n +2 ; i++)parent[i]=i;
       for(int i =0 ;i<m ;i++){
           int k ;
           cin>>k;
           if(k==0)continue;
           int begin ;
           cin>>begin;
           for(int j =1;j<k ; j ++){
               int num ;
               cin>>num;
               makeParent(begin,num);
           }
       }
       map<int, int> mm ;
       for(int  i = 1 ;i <=n ;i++ ){
           mm[getParent(i)]++;
       }
      for(int i = 1 ;i<= n ;i++){
          cout<<mm[getParent(i)]<<" ";
      }
      cout<<endl;
 
}
