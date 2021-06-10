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
const int N = 315; //316;
const int maxN = 1e5;
 
void readArray(int n, vector<int> &a) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 143; i++) {
        for (int j = 0; j < 201; j++) {
            int three = n - i * 7 - j * 5;
            if (three < 0 || three % 3 != 0)
                continue;
            three /= 3;
            if (i * 7 + j * 5 + (three) * 3 == n) {
                cout << three << space << j << space << i << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}
 
int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
