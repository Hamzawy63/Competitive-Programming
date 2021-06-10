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
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    vector<int> decrypt(4 * 1000000 + 9) ;
    vector<int> all_values;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        all_values.pb(l);
        all_values.pb(r);
        a.pb({l, r});
    }
    sort(all_values.begin(), all_values.end());
   // all_values.resize(     distance(all_values.begin() , unique(all_values.begin(), all_values.end()))    ) ;
    int cnt = 0;
    ll last = -10000000000 ;
    for (auto v : all_values) {
        if(v == last ) continue;
        else {
            mp[v] = cnt;
            decrypt[cnt] = v;
            cnt +=2 ;
            last = v ;
        }
    }
    for (auto &p : a) {
        p.ff = mp[p.ff];
        p.ss = mp[p.ss];
    }
    vi pre(cnt + 1);
    for (auto p : a) {
        pre[p.ff] += 1;
        pre[p.ss + 1] -= 1;
    }
    for (int i = 1; i < (int) pre.size(); i++) {
        pre[i] += pre[i - 1];
    }
 
//    for(int i=0;i<(int)pre.size();i++) cout << i << space ;
//    cout <<endl;
//    for(int i=0;i<(int)pre.size();i++) cout << pre[i] << space ;
//    cout <<endl;
 
    vector<pair<int, int>> ans;
    bool started = false;
    for (int i = 0; i < (int)pre.size();) {
        if (pre[i] < k) i++;
        else {
            int L = i;
            int R = i;
            while (i < (int) pre.size() && pre[i] >= k) {
                R = i;
                i++;
            }
            ans.pb({L,R}) ;
        }
    }
    cout << (int)ans.size() <<endl;
    for(auto p : ans ) {
        cout << decrypt[p.ff] << space << decrypt[p.ss] <<endl;
    }
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
