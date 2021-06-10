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
    string s;
    cin >> s;
    map<char, char> mp;
    mp[']'] = '[';
    mp['}'] = '{';
    mp[')'] = '(';
    mp['>'] = '<';
 
    stack<char> st;
    int ans = 0;
    bool ok = true ;
    for (auto c : s) {
        if (c == '{' || c == '(' || c == '[' || c == '<')
            st.push(c);
        else {
            if ((int) st.size() == 0) {
                ok = false;
                break;
            }else {
                if(mp[c] == st.top()) {
                    st.pop() ;
                }else {
                    ans ++ ;
                    st.pop() ;
                }
            }
        }
    }
    if(!ok || !(st.empty())){
        cout << "Impossible" << endl;
    }else {
        cout << ans << endl;
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
