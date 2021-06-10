#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
///=========================================================================================================
 
void solve() {
   int n ;
   cin>> n ;
   int sum =0;
   vector<int>odd;
   for(int i = 0;i<n ; i++){
       int a ;
       cin>>a;
       if(a>0&&(a%2==0)){
           sum+=a;
       }
       else if(a%2==0)continue;
       else{
           odd.push_back(a);
       }
   }
   sort(odd.begin(),odd.end() , greater<>() );
 
   for(int i = 0 ; i<odd.size() ; i++){
       if(odd[i]>0){
           sum+=odd[i];
       }else{
           if((i) % 2 == 0 ) {
               if(i==0){
                   sum+=odd[0];
               }else
               sum -= min(-1 * odd[i] ,  odd[i-1] );
           }
           break;
       }
   }
   if(odd.back()>0 && odd.size() %2 == 0 ){
       sum-=odd.back();
   }
   cout<<sum<<endl;
}
 
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
