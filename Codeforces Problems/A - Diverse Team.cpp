#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
typedef long long int ll;
using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
 
int main() {
    int n, k;
    cin >> n >> k;
    unordered_set<int> set;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        int b = set.size();
        set.insert(a);
        int after = set.size();
        if (b != after) ans.push_back(i);
    }
    if (ans.size() >= k ) {
        cout << "YES" << endl;
        for (int i = 0; i < k ; i++) cout << ans[i] << space;
    } else { cout << "NO" << endl; }
 
 
    return 0;
 
}
