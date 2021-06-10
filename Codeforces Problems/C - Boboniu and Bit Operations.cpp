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
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = 1000000007;
 
bool valid(int a, int target) {
    //cerr << a << space << target <<endl;
    for (int i = 1; i <= 512; i *= 2) {
        bool f = (i & a) != 0;
        bool s = (i & target) != 0;
        if (f && !s) return false;
    }
    return true;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int j = 0; j < m; j++)cin >> b[j];
    int maxN = 512;
    for (int po = 0; po <= maxN; po++) {
        bool can = true;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < m; j++) {
                ll and_val = (a[i] & b[j]);
                if (valid(and_val, po)) ok = true;
            }
            can = can && ok;
        }
        if (can) {
            cout << po << endl;
            return;
        }
    }
 
 
//    int n, m;
//    cin >> n >> m;
//    vector<int> a(n), b(n);
//    cerr << " dfasdfda" << endl;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int j = 0; j < m; j++) {
//        cin >> b[j];
//    }
//    cerr << " dfasdfda" << endl;
//    int maxN = 512;
//    for (int possible = 0; possible <= maxN; possible++) {
//        cerr << possible << endl;
//        bool ok = true;
//        for (int i = 0; i < n; i++) {
//            bool okk = false;
//            for (int j = 0; j < m; j++) {
//                int and_val = a[i] & b[j];
//                okk = ok || valid(and_val, possible);
//            }
//            ok = ok && okk;
//        }
//        if (ok) {
//            cout << possible << endl;
//            return;
//        }
//    }
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
//    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
