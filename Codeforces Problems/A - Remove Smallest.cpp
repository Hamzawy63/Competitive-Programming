#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
 
void solve() {
    int n;
    cin >> n;
    set<int> st;
    vi a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (!st.count(t)) {
            a.pb(t);
            st.insert(t);
        }
    }
    sort(a.begin() , a.end()) ;
    bool ok = true ;
    for(int i=1;i<(int)a.size();i++){
        ok = ok && ((a[i] - a[i-1]) == 1 );
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
//#define _DEBUG
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
