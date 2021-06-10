#include <bits/stdc++.h>
 
using namespace std;
#define space " "
using ll =  long long int;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            cout << 1 * a[i - 1] << space;
        }else {
            cout << -1 * a[i+1] <<space ;
        }
    }

















