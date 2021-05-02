#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.0000000001
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
const int maxN = 500 * 500 + 3;
const ll inf = 1e14;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];
    vector<int> len;
    for (int i = 0; i < n; i++) {
        if (len.empty()) len.push_back(a[i]);
        else {
            int idx = lower_bound(len.begin(), len.end(), a[i]) - len.begin();
            int sz = (int) len.size();
            if (idx == sz) {
                len.push_back(a[i]);
            } else {
                len[idx] = a[i];
            }
        }
    }
    cout << (int) len.size() << endl;

}