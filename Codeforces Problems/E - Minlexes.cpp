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
const int N = 4 * 1e5 + 2;
int maxN = 1e5 + 3;
vector<deque<int>> first(maxN);
vector<deque<int>> last(maxN);
vector<int> sz(maxN);
string s;
 
void reform(int i) {
    first[i] = first[i + 1];
    last[i] = last[i + 1];
    int n = (int) first[i].size();
    int m = (int) last[i].size();
    if (m < 2) {
//        last[i] = last[i + 1];
        last[i].push_front(i);
    } else {
        //   first[i] = first[i + 1];
        first[i].push_front(i);
        n++;
        while (n > 8) {
            first[i].pop_back();
            n--;
        }
    }
}
 
vector<int> get(int i) {
    vi ans;
    int n = (int) first[i].size();
    int m = (int) last[i].size();
    if (n == 0) {
        if (m > 0) ans.push_back(last[i].front());
        if (m > 1)ans.push_back(last[i].back());
    } else if (n == 1) {
        ans.push_back(first[i].front());
        if (m > 0) ans.push_back(last[i].front());
    } else {
        int tmp = first[i].front();
        ans.push_back(tmp);
        first[i].pop_front();
        ans.push_back(first[i].front());
        first[i].push_front(tmp);
    }
    return ans;
}
 
void print(int i) {
    string ans = "";
    string R = "";
    if (sz[i] <= 10) {
        while (first[i].empty() == false) {
            int idx = first[i].front();
            ans += s[idx];
            first[i].pop_front();
        }
        while (!last[i].empty()) {
            int idx = last[i].front();
            ans += s[idx];
            last[i].pop_front();
        }
    } else {
        int cnt = 5;
        while (cnt) {
            int idx = first[i].front();
            ans += s[idx];
            first[i].pop_front();
            cnt--;
        }
        ans += "...";
        while (!last[i].empty()) {
            int idx = last[i].front();
            ans += s[idx];
            last[i].pop_front();
        }
    }
    cout << ans << endl;
}
 
 
void solve() {
    cin >> s;
    int n = (int) s.size();
    last[n - 1].push_back(n - 1);
    sz[n - 1] = 1;
    vector<char> nd(n, '*');
    for (int i = n - 2; i >= 0; i--) {
        if (i == n - 9) {
            int xd = 32;
        }
        vi nxt = get(i + 1);
        int ls = (int) nxt.size();
        if (ls == 0) {
            sz[i] = 1;
            last[i].push_back(i);
            nd[i] = '*'; // defautl
        } else if (ls == 1) {
            int last_taken_idx = nxt.front();
            char first_char = s[last_taken_idx];
            if ((first_char == s[i]) && (i + 1 == last_taken_idx)) {
                sz[i] = 0;
                // default
            } else {
                last[i].push_back(i);
                last[i].push_back(last_taken_idx);
                sz[i] = 2;
                nd[i] = first_char;
            }
 
        } else if (ls == 2) {
            int last_taken_idx = nxt.front();
            char first_char = s[last_taken_idx];
            bool should_put = (nd[i + 1] != '*') && (nd[i + 1] > s[i]);
            if (!should_put && (first_char == s[i]) && (i + 1 == last_taken_idx)) {
                sz[i] = sz[i + 2];
                first[i] = first[i + 2];
                last[i] = last[i + 2];
                nd[i] = nd[i + 2];
            } else {
                sz[i] = sz[i + 1] + 1;
                reform(i);
                if (first_char == s[i])
                    nd[i] = nd[i + 1];
                else
                    nd[i] = first_char;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sz[i] << space;
        print(i);
    }
}
 
int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
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
