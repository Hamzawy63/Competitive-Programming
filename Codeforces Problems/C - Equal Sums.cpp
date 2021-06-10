#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <map>
#include <set>
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "
 
typedef long long int ll;
using namespace std;
int main() {
    IO;
    int q;
    cin >> q;
    vector<int> arr[q + E];
    map<int, unordered_set<int>> avl;
    int sum[q + E];
    for (int k = 0; k < q; k++) {
        int n;
        cin >> n;
        int s = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr[k].push_back(a);
            s += a;
 
        }
        for (int j = 0; j < n; j++) {
            int t = s - arr[k][j];
            if (avl.count(t))
                avl[t].insert(k);
            else {
                unordered_set<int> vec;
                vec.insert(k);
                avl.insert(std::pair<int, unordered_set<int>>(t, vec));
            }
 
        }
        sum[k] = s;
    }
    int newsum = 0, f = -1, s = -1;
    for (std::map<int, unordered_set<int>>::iterator it = avl.begin(); it != avl.end(); ++it) {
        if (it->second.size() > 1) {
            newsum = it->first;
            int l = 0;
            for (std::unordered_set<int>::iterator it2 = it->second.begin();
                 l < 2 && it2 != it->second.end(); ++it2, l++) {
                {
                    if (l == 0) f = *it2;
                    if (l == 1) s = *it2;
                }
            }
            break;
        }
    }
 
 
    if (f == -1) {
        cout << "NO";
    } else {
        int idx1 = 0;
        int idx2 = 0;
        for (int i = 0; i < arr[f].size(); i++)
            if (arr[f][i] == sum[f] - newsum) idx1 = i + 1;
 
        for (int i = 0; i < arr[s].size(); i++)
            if (arr[s][i] == sum[s] - newsum) idx2 = i + 1;
 
        cout << "YES" << endl;
        cout << f + 1 << space << idx1 << endl;
        cout << s + 1 << space << idx2 << endl;
    }
 
 
    return 0;
 
}
