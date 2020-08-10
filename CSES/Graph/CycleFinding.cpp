#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Edge {
    int u, v;
    ll cost;
};
vector<Edge> g ;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;v-- ;
        g.push_back({u,v,cost}) ;
    }
    vector<ll> d(n,0) , par(n);
    int node_x= -1 ;
    for(int i=0;i<n;i++){
        node_x = -1 ;
        for(auto edge : g ) {
            if(d[edge.v] > d[edge.u]  + edge.cost) {
                d[edge.v] = d[edge.u]  + edge.cost ;
                par[edge.v] = edge.u ;
                node_x = edge.v ;
            }
        }
    }
    if(node_x != -1  ){
        cout << "YES " << endl;
        for(int i=0;i<n;i++){
            node_x = par[node_x] ;
        }
        int cur = node_x ;
        vector<int> res = {cur};
        cur = par[cur] ;
        while(cur != node_x ) {
            res.push_back(cur) ;
            cur = par[cur] ;
        }
        res.push_back(node_x) ;
        reverse(res.begin() , res.end()) ;
        for(auto v : res ) cout << v+1 << " " ;
        cout << endl;
    }else {
        cout << "NO" << endl;
    }

}
