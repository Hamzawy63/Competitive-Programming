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
#define ACCURATE cout << fixed << setprecision(12)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
 
int freq[1000005];
 
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
 
    IO;
    int n;
    cin >> n;
    ll last = n;
    for (int i = 0; i < n; i++) freq[i] = 0;
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) {
                n /= i;
                freq[i]++;
            }
        }
    }
    int res = 1;
    int maxFactor = 1 ;
    for(int i = 0 ; i< (int)primes.size() ; i++ ){
        maxFactor = max(maxFactor, freq[primes[i]]) ;
    }
 
    int powerOfTwo = maxFactor & (maxFactor -1) ;
    int bits = log2(maxFactor) + 1 ;
    int target = powerOfTwo == 0 ? maxFactor : 1<<(bits) ;
    int steps = (log2(target) ) ;
    bool check = false ;
 
    for(int i= 0 ; i < (int)primes.size() ; i++) {
        res*= primes[i];
        if(target - freq[primes[i]] !=  0 ) if(!check ) {steps++ ; check = true ; }
    }
    cout << res << space << steps ;
 
    return 0;
}
