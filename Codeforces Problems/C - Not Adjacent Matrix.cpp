#include <bits/stdc++.h>
/*
Created on  by Hamza Hassan:
*/
#define space " "
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
using namespace std;
 
void read(vector<int> &a, int n = -1);
 
void print(vector<int> &a, int n = -1);
 
const bool query = true ;
 
void solve() {
    int n;
    cin >> n;
    if(n ==  2) {
        cout << -1 << endl;
        return ;
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        a[i][i] = (i + 1);
    }
    int nxte = n + 1;
    if (nxte % 2 == 1) nxte += 1;
    int nxto = n + 1;
    if (nxto % 2 == 0) nxto++;
    for (int i = 1; i < n; i++) {
        int ii = 0, jj = i;
        while (ii < n && jj < n) {
 
            a[ii][jj] = nxte;
            nxte += 2;
            ii++ ;
            jj++ ;
        }
    }
    for (int i = 1; i < n; i++) {
        int ii = i, jj = 0;
        while (ii < n && jj < n) {
            a[ii][jj] = nxto;
            nxto += 2;
            ii++ ;jj++ ;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << ' ' ;
        }
        cout << endl;
    }
 
}
 
 
int main() {
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
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
