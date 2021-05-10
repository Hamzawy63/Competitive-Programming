#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
        int q = (int) queries.size();
        int n = (int) rooms.size();
        vector<int> idx(q);
        int n ; 
        for (int i = 0; i < q; i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });
        set<int> st;
        set<int , greater<int>> st2;
        for (int i = 0; i < n; i++) {
            st.insert(rooms[i][0]);
            st2.insert(rooms[i][0]);
        }
        sort(rooms.begin(), rooms.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
//        cerr << "the queries" << endl;
//        for (int i = 0; i < q; i++) {
//            cerr << queries[idx[i]][1] << ", " << queries[idx[i]][0] << endl;
//        }
//        cerr << "the rooms " << endl;
//        for (int i = 0; i < n; i++) {
//            cerr << rooms[i][1] << ' ' << rooms[i][0] << endl;
//        }
        vector<int> ans(q);
        int L = 0;
        for (int i = 0; i < q; i++) {
            int ii = idx[i];
            int min_size = queries[idx[i]][1];
            int target_id = queries[idx[i]][0];
            while (L < n && rooms[L][1] < min_size) {
                st.erase(rooms[L][0]);
                st2.erase(rooms[L][0]);
                L++ ;
            }
            if(st.empty()){
                ans[ii] = -1 ;
                continue ;
            }
            auto lb = st2.upper_bound(target_id);
            auto rb = st.lower_bound(target_id);
            if (lb == st2.end() && rb == st.end()) {
                ans[ii] = -1;
            } else if (lb == st2.end() && rb != st.end()) {
                ans[ii] = *rb;
            } else if (rb == st.end() && lb != st2.end()) {
                ans[ii] = *lb;
            } else {
                int interval1 = target_id - *lb;
                int interval2 = *rb - target_id;
                if (interval1 <= interval2) {
                    ans[ii] = *lb;
                } else {
                    ans[ii] = *rb;
                }
            }
        }


        return ans;
    }

};

int main() {
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<vector<int>> rooms, queries;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            rooms.push_back({a, b});
        }
        for (int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            queries.push_back({a, b});
        }
        Solution s;
        vector<int> ans = s.closestRoom(rooms, queries);
        for (auto v : ans) {
            cout << v << ' ';
        }
        cout << endl;
    }

}