#include <bits/stdc++.h>
 
using namespace std;
 
void read(vector<int> &a, int n = -1);
 
void print(vector<int> &a, int n = -1);
 
const bool query = true;
 
 
void solve() {
    int n;
    cin >> n;
    vector<long long int > u(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i];
        u[i] -=1 ;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<long long int >> g(n );
    vector<long long int > ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        g[u[i]].push_back(s[i]);
    }
    for(int i=0;i<n;i++) sort(g[i].begin() , g[i].end() , greater<long long int >()) ;
    for (int i = 0; i < n; i++) {
        vector<long long int > &U = g[i];
 
        if(U.empty() ) continue ;
        int sz = (int) U.size();
 
        vector<long long int> pre(sz + 1, 0);
        for (int j = 1; j <= sz; j++) {
            pre[j] = pre[j - 1] + U[j-1];
        }
 
        vector<long long int> res(sz + 1, 0);
        res[sz] = pre[sz];
        res[1] = pre[sz];
        int ptr = sz - 1 ;
        for (int j = sz - 1; j > 1; j--) {
            // check if there is some mulitple
            if (sz % j == 0) {
                res[j] = pre[sz];
                ptr = sz - 1 ;
            }else {
                int md = sz % j ;
                res[j] = pre[sz - md ];
                ptr -=1 ;
 
            }
 
        }
//        for(int j=1;j<=sz ;j ++){
//            cerr << res[j] << ' ';
//        }
//        cerr << endl;
 
        for (int j = 1; j <= sz; j++) {
            ans[j] += res[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
 
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
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
