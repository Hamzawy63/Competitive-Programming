#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
 
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
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
 
///=========================================================================================================
// bda
// b
//
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    //vector<pair<char, int> > mca(n);
    vector<int> mca(n);
    mca[n - 1] = n - 1;
    char min_char = s[n - 1];
    int min_char_idx = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        mca[i] = min_char_idx;
        if (s[i] <= min_char) {
            min_char_idx = i;
            min_char = s[i];
        }
 
    }
    stack<char> t;
    int index = min_char_idx;
    string u = "";
    for (int i = 0; i < n; i++) {
        if (i < index) {
            t.push(s[i]);
        } else if (i == index) {
            if ((int) t.size() != 0) {
                while ((!t.empty()) && (t.top() <= s[i])) {
                    u += t.top();
                    t.pop();
                }
            }
            u += s[i];
            index = mca[i];
            while ((!t.empty()) && (t.top() <= s[index])) {
                u += t.top();
                t.pop();
            }
        }
    }
    while (!t.empty()) {
        u += t.top();
        t.pop();
    }
    cout << u << endl;
 
 
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
 
 
//       ababkamts
//    t-> bbk
//    u->aaa
