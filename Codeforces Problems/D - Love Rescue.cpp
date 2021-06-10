#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
vector<int> par(27);
 
int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}
 
void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    par[aa] = bb;
}
 
string s, t;
 
void solve() {
    int n;
    cin >> n;
    cin >> s;
    cin >> t;
    vector<int> f(26, 0);
    for (int i = 0; i < 26; i++) par[i] = i;
    for (int i = 0; i < n; i++) {
        f[s[i] - 'a']++;
        f[t[i] - 'a']++;
        merge(s[i] - 'a', t[i] - 'a');
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (f[i] > 0) {
            int k = find(i);
            if (k != i) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < 26; i++) {
        if (f[i] > 0) {
            int k = find(i);
            if (k != i) {
                cout << (char) ('a' + i) << space << (char) ('a' + k) << endl;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
