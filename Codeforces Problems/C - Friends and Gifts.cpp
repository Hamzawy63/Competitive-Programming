#include <bits/stdc++.h>
using namespace std;
int main() {
int q , n ,a ,b  ; 
cin >>q ;
while(q--){
 
 cin >> n >>a >>b ;
 int tmp = 0 , m = 0  ; 
 string res = "yes" ;
 for(int i = 0 ; i < a ; i++) {
  cin >> tmp ;
 m = max(tmp , m  );
 }
 for(int i = 0 ; i < b ;i++){
 cin >> tmp ;
 if(tmp > m)
  res = "no";
 
 }
cout << res << endl ;                  
}    
return 0 ; 
   
}
