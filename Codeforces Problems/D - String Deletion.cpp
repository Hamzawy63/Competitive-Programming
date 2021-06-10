#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define endll '\n'
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
const int maxN = 1e5;
int n;
vi par;
 
int get_parent(int a) {
    if (par[a] == a) {
        return a;
    } else {
        return par[a] = get_parent(par[a]);
    }
}
 
void combine(int a, int b) {
    int p1 = par[min(a, b)];
    int p2 = par[max(b, a)];
    if (p1 != p2) {
        par[p1] = p2;
    }
}
 
void solve() {
    cin >> n;
    par.clear();
    par.resize(n + 2);
    string s;
    cin >> s;
    par[n] = n;
    par[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        par[i] = i;
        if (s[i] == s[i + 1]) par[i] = i;
        else combine(i, i + 1);
    }
    int ans = 0;
    set<int> st;
    for (int i = 0; i < n;) {
        if (st.count(i)) {
            i++;
            continue;
        }
        int next = get_parent(i);
        if (next == n) {
            int len = (n - i);
            for(auto v : st) {
                if(v >= i && v < n ) len-- ;
            }
            ans += ((len + 1) / 2);
            break;
        } else {
            int took = get_parent(i);
            st.insert(took);
            combine(took, took + 1);
        }
        while ((i < n - 1) && (s[i] == s[i + 1])) {
            i++;
        }
        i++;
        ++ans;
 
    }
    cout << ans << endl;
 
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
