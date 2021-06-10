#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define FINF 1000000000000
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
#define ar array
 
void solve() {
    int n, m;
    cin >> n;
    for (int i = 0; 3 * i <= 100; i++) {
        for (int j = 0;  7 * j <= 100; j++) {
            if (3 * i + 7 * j == n) {
                cout <<"YES" <<endl;
                return ;
            }
        }
    }
    cout << "NO" <<endl;
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
