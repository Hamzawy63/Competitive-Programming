#include <iostream>
#include<bits/stdc++.h>
#define E 10
#define space " "
using namespace std;
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
void debug(){
    cout <<  "Here we are " << endl ;
}
 
int main() {
    //IO;
    int n ;
    cin >> n ;
//    vector<int> a ;
    int a[n+E] ;
        for(int i =0  ;i < n ;i++) {
        int t ;
        cin >> t ;
        a[i] = t ;
    //    a.push_back(t) ;
    }
    int res = 2e9 ;
    if(n < 3){
        cout << 0 << endl ;
        return 0;
    }
    for(int i = -1 ; i<2 ; i++) {
        a[0]+=i ;
        for(int j = -1 ; j<2 ;j++)  {
            //debug() ;
            bool ok = true ;
            a[1]+=j ;
            int delta = a[1] - a[0] ;
            int cnt = abs(i) + abs(j) ;
            for(int k = 2 ; k< n ;k++) {
                if(abs(a[k] - (delta * k + a[0])) <2){
                    //cout << "found a match " << endl;
                    cnt +=abs(a[k] - (delta * k + a[0]))  ;
                }else{
                    ok = false ;
                    break ;
                }
            }
            if(ok) res = min(res , cnt ) ;
            a[1]-=j ;
        }
        a[0]-=i ;
    }
    if(res == 2e9) res = -1 ; 
    cout << res << endl ;
    return 0 ;
}
