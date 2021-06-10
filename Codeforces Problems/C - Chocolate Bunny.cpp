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
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
bool YES = true;
bool NO = false;
 
void check(bool ok) {
    if (ok)cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
//#define _DEBUG
int query(int a, int b) {
    cout << "? " << a << space << b << endl;
    int x;
    cin >> x;
    return x;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1, -1);
    set<int> st, st2;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
        st2.insert(i);
    }
    int nn = n;
    while (nn > 1) {
        int ii = *st.begin();
        int jj = *st.rbegin();
        int first = query(ii, jj);
        int second = query(jj, ii);
        if (first > second) {
            a[ii] = first;
            // cerr << ii << endl;
            st.erase(ii);
            st2.erase(first);
        } else {
            // cerr << jj << endl;
            a[jj] = second;
            st.erase(jj);
            st2.erase(second);
        }
        nn--;
    }
    cout << "! " << space;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            a[i] = *st2.begin();
        }
        cout << a[i] << space;
    }
    cout << endl;
 
 
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
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
