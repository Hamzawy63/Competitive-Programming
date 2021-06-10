#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
int query = 0;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n - k + 1);
    for (int i = 0; i < n-k+1; i++) {
        cin >> a[i];
    }
    vector<string> ans(n);
    string cur = "Abcdefghij";
    for (int i = 0; i < n; i++) {
        ans[i] = cur;
        next_permutation(cur.begin()+1, cur.end());
    }
    for (int i = 0; i < n - k + 1; i++) {
        if (a[i] == "NO") {
            ans[i + k - 1] = ans[i];
        }
    }
    for (auto s : ans) {
        cout << s << space;
    }
    cout << endl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    if (query == 1)
        cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
