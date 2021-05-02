#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const int maxN = 1e5 + 3;
vector<int> p(maxN);

int find(int a) {
    if (p[a] == a) return a;
    else return p[a] = find(p[a]);
}

void merge(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa < bb) {
        p[bb] = aa;
    } else {
        p[aa] = bb;
    }
}


void solve() {
    string s, t, ans;
    cin >> s >> t >> ans;
    int n = 26;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < (int) s.size(); i++) {
        merge(s[i] - 'a', t[i] - 'a');
    }
    for (int i = 0; i < (int) ans.size(); i++) {
        char new_chr = (char) ('a' + find(ans[i] - 'a'));
        ans[i] = new_chr;
    }
    cout << ans << endl;
}

int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}