#include <bits/stdc++.h>

using namespace std;

template<class type>
class Fenwick {
    // zero based fenwick tree
    int n;
    vector<type> fen;
    bool initialized; // to make sure the methods are used after calling init .

public:
    Fenwick() {
        initialized = false;
    }

    void init(int n) {
        initialized = true;
        this->n = n;
        fen.resize(n);
    }

    void init(vector<type> &fen) {
        initialized = true;
        this->fen = fen;
        n = (int) fen.size();
    }

    type query(int L) {
        assert(initialized);
        type ans = 0;
        while (L >= 0) {
            ans += fen[L];
            L = (L & (L + 1)) - 1;
        }
        return ans;
    }

    type range_query(int L, int R) {
        assert(initialized);
        assert(R < n);
        assert(L >= 0);
        type ans = query(R);
        if (L) ans -= query(L - 1);


        return ans;
    }

    type suffix_query(int L) {
        if (L >= n) return 0;

        assert(L >= 0);

        type ans = query(n - 1);
        if (L) ans -= query(L - 1);
        return ans;
    }

    void update(int idx, type delta) {
        assert(initialized);
        assert(idx >= 0);
        assert(idx < n);
        while (idx < n) {
            fen[idx] += delta;
            idx = (idx | (idx + 1));
        }
    }
};


struct Data {
    int query_idx;
    int parity;
    int K;
};

const int mxN = 30000;
vector<Data> g[mxN + 3];
vector<int> all;

int main() {
#ifdef  _SHIT
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    int q;
    cin >> q;
    vector<int> ans(q);
    for (int qq = 0; qq < q; qq++) {
        int L, R, k;
        cin >> L >> R >> k;
        L -= 1;
        R -= 1;
        all.push_back(k);
        if (L > 0)g[L - 1].push_back({qq, -1, k});
        g[R].push_back({qq, 1, k});
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin() , all.end()) , all.end()) ;
    Fenwick<int> fen;


    fen.init((int) all.size() + 5);
    auto hash = [&](int val) {
        int idx = lower_bound(all.begin() , all.end() , val ) - all.begin() ;
        return idx ;
    };

    for (int i = 0; i < n; i++) {
        // add the value to the tree
        fen.update(hash(a[i]), 1);
        for (auto to : g[i]) {
            int query_idx = to.query_idx;
            int K = to.K;
            int parity = to.parity;
            int res = 0;
            res = fen.suffix_query(hash(K + 1));
            ans[query_idx] += res * parity;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
//    cout << '\n' ;
    return 0;
}