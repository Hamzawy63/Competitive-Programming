#include <bits/stdc++.h>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long double
const int mxN = 1 * 100 * 1000 + 5;
vector<pair<int, int>> g[mxN];
 
void solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<string> ans;
    for (int i = 0; i < n; i++) {















































