#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
 
int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    vector<int> ans;
    int lb = 0, rb = n;
    while (lb <= rb) {
        int mb = (lb + rb) / 2;
        int sumOnes = 0;
        int sumZeros = 0;
        vector<int> temp;
        for (int i = 0; i < mb; i++) {
            sumOnes += a[i];
            sumZeros += (1 ^ a[i]);
        }
        bool ok = false;
        int L = 0, R = mb - 1;
        while (R < n) {
            if (sumZeros <= k) {
                ok = true;
                for (int i = 0; i < L; i++) temp.push_back(a[i]);
                for (int i = L; i <= R; i++)temp.push_back(1);
                for (int i = R + 1; i < n; i++)temp.push_back(a[i]);
                break;
            } else {
 
                if(a[L] == 0 ) sumZeros-- ;
                else sumOnes-- ;
 
                if(R+1 < n ){
                    if (a[R + 1] == 1) sumOnes++;
                    else sumZeros++;
                }
                L++ ;
                R++ ;
            }
        }
 
        if (ok) {
            res = mb;
            ans = temp;
            lb = mb + 1;
        } else {
            rb = mb - 1;
        }
    }
    cout << res << endl;
    for (auto v : ans) {
        cout << v << space;
    }
    cout << endl;
 
 
}
