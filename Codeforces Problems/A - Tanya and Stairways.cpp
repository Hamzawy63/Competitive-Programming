#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <unordered_map>
 
typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    vector<int> res;
    for(int i = 0 ; i< n ;i++) cin >> a[i] ;
    for (int i = 0; i < n;) {
        if (a[i] == 1) {
            ans++;
            int j = i+1;
            for (; j < n && a[j] != 1; j++){}
            res.push_back(a[j - 1]);
            i = j  ;
        }
    }
    cout << ans << endl;
    for (auto i : res) cout << i << space;
 
 
    return 0;
}
