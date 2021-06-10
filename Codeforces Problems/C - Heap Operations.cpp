#include <bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long double
const int mxN = 1 * 100 * 1000 + 5;
vector<pair<int, int>> g[mxN];
 
void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = 0;
        if (s[0] == 'i' || s[0] == 'g') {
            cin >> a;
        }
        if (s[0] == 'i') {
            pq.push(a);
            ans.push_back("insert " + to_string(a));
        } else if (s[0] == 'g') {
            while (!pq.empty() && pq.top() < a) {
                pq.pop();
                ans.push_back("removeMin");
            }
            if (pq.empty() || pq.top() > a) {
                pq.push(a) ; 
                ans.push_back("insert " + to_string(a));
            }
 
            ans.push_back(s + " " + to_string(a));
 
 
        } else {
            // re minimum
            if (pq.empty()) {
                pq.push(0);
                ans.push_back("insert 0 ");
            }
            pq.pop();
            ans.push_back("removeMin");
        }
    }
    cout << ans.size() << '\n';
    for (auto &c : ans) cout << c << '\n';
    cout << '\n';
}
 
int query = 0;
 
int main() {
    IO;
    int q = 1;
    if (query) cin >> q;
    while (q--) {
        solve();
    }
}
