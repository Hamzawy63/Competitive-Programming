#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
 
int k,n,a[500005]; map<int,int> m;
 
void solve() {
 
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int counter = 0,sum = 0,res = 0,l,r,last = 0;
    for(int i = 0; i < n; i++){
        int &ele= m[a[i]];
        if (ele == 0){
            while (counter == k) {
                int &temp = m[a[last]]; last++; temp--;
                if (temp==0){
                    counter--;
                }
                sum--;
            }
            ele++;
            counter++;
        } else {
            ele++;
        }
        sum++;
        if (sum > res){
            res = sum;
            l = last;
            r = i;
        }
    }
    cout << l+1 << " " << r+1;
}
 
int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
