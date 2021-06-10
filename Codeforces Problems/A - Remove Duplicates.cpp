#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
 
int main() {
    IO;
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    int freq[1000 + E];
    memset(freq, 0, sizeof freq);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t = b[n - i - 1];
        if (!freq[t]) {
            //cout << " Now we add the " << t   <<  "in the index of" << i << endl ;
            a.push_back(t);
            freq[t] = 1;
        }
    }
    reverse(a.begin() , a.end()) ;
    cout << a.size() << endl;
    for(int i =0  ; i < a.size() ; i++) cout << a[i] << space  ;
}
