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
string s = "";
string t = "";
int n;
vector<string> ans;

void permute() {
    if (t.size() == n) {
        ans.push_back(t);
        return;
    }
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] != '?') {
            char pack = s[i];
            t += s[i];
            s[i] = '?';
            permute();
            t.pop_back();
            s[i] = pack;
        }
    }
}
void solve() {
    cin >> s;
    n = (int) s.size();
    permute();
    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
    cout << ans.size() << endl;
    for (auto s : ans) {
        cout << s << endl;
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