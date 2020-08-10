// Dijkstra algorithm was implemented using Set data structure :)

#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 * 100 + 3;
typedef long long int ll ;
const ll  INF = 10000000000000000 ;
vector<pair<int , ll > > g[maxN] ;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v,cost ;
        cin >> u >> v >> cost ;
        u--;
        v--;
        g[u].push_back({v , cost});
        //g[v].push_back({u, cost });
    }
    vector<ll> d(n , INF) ;
    d[0] =0LL ;
    //priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    set<pair<ll , int>> st ;
    st.insert({0 , 0 }) ;
    while(!st.empty()) {
        int cur = (*st.begin()).second ;
        ll cost = (*st.begin()).first ;
        st.erase(st.begin()) ;
        if(cost != d[cur]) {
            continue ;
        }
        for(auto adj : g[cur]) {
            int to = adj.first ;
            ll weight = adj.second ;
            if(cost + weight < d[to]) {
                d[to] = cost + weight ;
                st.erase(make_pair(d[to],to)) ;
                st.insert({d[to] , to}) ;
            }
        }
    }
    for(auto  v : d ) cout << v << " " ;
    cout << endl;

}
