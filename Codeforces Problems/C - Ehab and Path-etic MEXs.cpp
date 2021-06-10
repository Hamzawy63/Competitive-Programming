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
#define ACCURATE cout << fixed << setprecision(6)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define MAT_SIZE 5
 
//#define _DEBUG
using namespace std;
 
//#define _DEBUG
//====================================================================================================
 
int inverse(ll, ll);
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
int powmod(ll a, ll b, ll mod) {
    //if (b < 0) return inverse(powmod(a, -1 * b));
    a %= mod;
    // b %= (mod - 1);
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
 
int inverse(ll a, ll primemod) {
    return powmod(a, 500000002, primemod);
}
 
//====================================================================================================
//====================================================================================================
//====================================================================================================
//==================
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int e[n + 3];
    set<int> all;
    for (int i = 0; i < n - 1; i++) all.insert(i);
    for(int i = 0 ; i < n ; i++ ) e[i] = 0 ;
    pair<pair<int, int>, int> edj[n + 3];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edj[i] = make_pair(make_pair(a, b), -1);
        e[a]++;
        e[b]++;
    }
    for (int i = 0; i < n - 1; i++) {
        int a = edj[i].first.first;
        int b = edj[i].first.second;
        if (e[a] == 1 || e[b] == 1) {
            edj[i].second = *all.begin();
            all.erase(*all.begin());
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (edj[i].second == -1) {
            edj[i].second = (*(--all.end()));
            all.erase(*(--all.end()));
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << edj[i].second << endl;
    }
 
 
    return 0;
}
