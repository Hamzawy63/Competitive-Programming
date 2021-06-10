#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int nn, b, p;
 
int go(int n) {
    if (n == 1) return 0;
    int exp = log2(n);
    int half = (1 << exp) / 2;
    int carry = n - (1 << exp);
    return ((1 << exp) * b + half + go(half  + carry));
}
 
void solve() {
    cin >> nn >> b >> p;
    cout << go(nn) << " " << p * nn << endl;













