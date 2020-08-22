#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second

int main() {
    int n, k;
    cin >> n >> k;
    vector<pi > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff;
        a[i].ss = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int need = k - a[i].ff - a[j].ff;
            int idx = lower_bound(a.begin() + j + 1   , a.end() , make_pair(need, 0 )) - a.begin() ;
            if(idx != n && a[idx].ff  == need ) {
                cout << a[i].ss << space << a[j].ss << space << a[idx].ss  << endl;
                return 0 ;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}