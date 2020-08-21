#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "

int main() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        int f, s;
        cin >> f >> s;
        pq.push({f, 1});
        pq.push({s, -1});
    }
    int ans = 0;
    int res = 0 ;
    while (!pq.empty()) {
        res += pq.top().second;
        pq.pop();
        ans = max(ans , res ) ;
    }
    cout << ans << endl;

}