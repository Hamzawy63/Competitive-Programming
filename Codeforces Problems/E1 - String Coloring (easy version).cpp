#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
vector<int> neigh[205];
int res[205];
 
bool dfs(int last, int i) {
    if (res[i] == last)
        return false;
    else if (res[i] != -1) cout << "What the hell is going on :(((" << endl;
    bool ok = true;
    res[i] = (1 + last) % 2;
  //  cout << "We colored the char with index = " << i << " with color = " << res[i] << endl << "  ";
    for (int j = 0; j < neigh[i].size(); j++) {
        int bro = neigh[i][j];
        if (res[bro] != -1 && res[bro] == res[i])
            return false;
        else if (res[bro] == -1) {
            ok &= dfs(res[i], bro);
        }
    }
  //  cout << endl;
  //  if (!ok) cout << "Could not color the character with index = " << i << endl;
    return ok;
}
 
//#define _DEBUG
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    IO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    pair<int, int> arr[n + E];
    for (int i = 0; i < n; i++) {
        arr[i] = make_pair(s[i] - 'a', i);
    }
    bool swapDone = true;
    while (swapDone) {
        swapDone = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i].first > arr[i + 1].first) {
                swapDone = true;
                neigh[arr[i].second].push_back(arr[i + 1].second);
                neigh[arr[i + 1].second].push_back(arr[i].second);
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) res[i] = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (res[i] == -1) ok &= dfs(1, i);
    }
 
    if (!ok) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << res[i];
    }
 
}
