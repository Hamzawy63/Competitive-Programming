#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <unordered_set>
#include <map>
#include <set>
#include <deque>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
 
vi a(8001);
 
void solve() {
    int q;
    cin >> q;
    while (q--) {
        int n ; cin >> n ;
        if(n < 4 ) cout<< -1 << endl;
        else {
            deque<int> deque = {3 , 1 , 4 , 2 };
            for(int i =5 ; i<=n ;i++ ) {
                if(i&1) deque.push_back(i) ;
                else deque.push_front(i) ;
            }
            while(deque.empty() == false ) {
                cout << deque.front() << space ;
                deque.pop_front();
            }
            cout << endl;
        }
    }
 
 
}
 
//cout << "Case #" << i << ": ";
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
