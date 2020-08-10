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

//#define _DEBUG
bool valid(int n) {
    bool even = n % 2 == 0;
    bool half_is_even = (n / 2) % 2 == 0;
    return even && half_is_even;
}

void solve() {
    int n;
    cin >> n;
    bool ok = false;
    vi a, b;
    if (valid(n)) {
        ok = true ;
        for (int i = 1; i <= n / 2; i++) {
            if (i % 2) {
                a.push_back(i);
                a.push_back(n - i + 1);
            } else {
                b.pb(i);
                b.pb(n - i + 1);
            }
        }

    } else if (valid(n - 3)) {
        ok = true ;
        a = {1, 2};
        b = {3};
        int nxt = 3;
        for (int i = 1; i <= (n - 3) / 2; i++) {
            if (i % 2) {
                a.pb(nxt + i );
                a.pb(nxt + ((n-3) -  i + 1 ));
            } else {
                b.pb(nxt + i);
                b.pb(nxt + (n-3) - i  + 1 );
            }
        }
    }
    if (ok) {
        cout << "YES" << endl;
        cout << a.size() << endl;
        for (auto v : a) cout << v << space;
        cout << endl;
        cout << b.size() << endl;
        for (auto v : b) cout << v << space;
        cout << endl;
    }else {
        cout << "NO" <<endl;
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
   // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}