#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)
int f[2 * 100000 + 4];
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int a[10][10];
        for (int i = 0; i < 9; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 9; j++) {
                a[i][j] = (s[j] - '0');
                if(j == 3 * (i%3) + i/3) if(a[i][j] == 9 ) a[i][j] = 1 ;else a[i][j] ++ ;
               // if(j == 3 * (i%3) + i/3) cout << i << space << j << endl ;
 
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << a[i][j];
            cout << endl;
        }
 
 
    }
    return 0;
 
}
