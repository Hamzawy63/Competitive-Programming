#include <bits/stdc++.h>
 
using namespace std;
 
void read(vector<int> &a, int n = -1);
 
void print(vector<int> &a, int n = -1);
 
const bool query = true;
 
void solve() {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int x  = (n-1 ) * m + (m-1 ) ; 
    if(x == k ) {
        cout << "YES"<< endl; 
    }else {
        cout << "NO" << endl; 
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    int qq = 1;
    if (query)
        cin >> qq;
    for (int i = 1; i <= qq; i++) {
        solve();
    }
}
 
 
void read(vector<int> &a, int n) {
    if (n == -1) n = a.size();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
 
void print(vector<int> &a, int n) {
    if (n == -1) {
        n = (int) a.size();
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
