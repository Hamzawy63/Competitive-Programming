#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int , int > > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first ;
        a[i].second = i+1 ;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l].first + a[r].first == x) {
            cout << a[l].second << space << a[r].second << endl;
            return 0;
        } else if (a[l].first + a[r].first > x) {
            r--;
        } else
            l++;
    }
    cout << "IMPOSSIBLE" << endl;

}