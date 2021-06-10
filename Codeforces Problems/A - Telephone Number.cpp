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





























