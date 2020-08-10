#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
        cout << n << " ";
    }
}
