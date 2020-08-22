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
    vector<ar<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int need = k - a[i][0] - a[j][0];
            int L = j + 1, R = n - 1;
            while (L < R) {
                if (a[L][0] + a[R][0] > need) R--;
                else if (a[L][0] + a[R][0] < need) L++;
                else {
                    cout << a[L][1] << space << a[R][1] << space << a[i][1] << space << a[j][1] << endl;
                    return 0;
                }
            }

        }

    }
    cout << "IMPOSSIBLE" << endl;
}