#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
 
int main() {
    IO;
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> h;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t%(a + b) == 0) h.push_back(a + b);
        else h.push_back(t % (a + b));
 
 
    }
    int res = 0;
    sort(h.begin(), h.end());
    for (int i = 0; i < n; i++) {
        if (h[i] - a <= 0) res++;
        else if (k > 0) {
            h[i]-=a  ;
            int c = (int) ceil(h[i] / (double)a);
            h[i] -= min(k, c) *(ll) a;
            k -= min(k, c);
            if(h[i] <= 0) res ++ ;
        }
    }
    cout << res << endl;
    return 0;
 
}
