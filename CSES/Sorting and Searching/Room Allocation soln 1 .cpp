#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
 
int main() {
    int n;
    cin >> n;
    multimap<int, int> mp;
    multiset<int , greater<int>> st;
    vector<int> ans(n);
    vector<pair<pair<int,int>,int>> a(n) ;
    for(int i=0;i<n;i++){
        cin >> a[i].first.first >> a[i].first.second ;
        a[i].second = i ;
    }
    sort(a.begin() , a.end()) ;
    for (int i = 0; i < n; i++) {
        int start, end;
        start = a[i].first.first  ;
        end = a[i].first.second ;
        int index_of_visitor = a[i].second ;
        auto itr = st.upper_bound(start);
        if (itr == st.end()) {
            st.insert(end);
            ans[index_of_visitor] = st.size() ;
//            ans.push_back((int) st.size());
            mp.insert(make_pair(end, (int) st.size()));
        } else {
            auto mp_itr = mp.lower_bound(*itr);
            int idx = (*mp_itr).second;
            mp.erase(mp_itr);
            mp.insert(make_pair(end, idx));
            st.erase(itr);
            st.insert(end);
            ans[index_of_visitor] = idx ;
//            ans.pb(idx);
        }
    }
    cout << (int)st.size() << endl;
    for(auto v : ans ) {
        cout << v << space  ;
    }
}