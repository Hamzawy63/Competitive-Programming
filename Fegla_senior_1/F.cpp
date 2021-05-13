#include <bits/stdc++.h>

using namespace std;
// https://www.spoj.com/problems/ORDERSET/en/
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
        assert(L<=R);
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

    int kth(int k) {
        int lb = 0, rb = n - 1;
        int ans = -1;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            int qq = query(mb) ;
            if (qq >= k) {
                ans = mb;
                rb = mb - 1;
            } else {
                lb = mb + 1;
            }
        }
        return ans;
    }
    int count_all(){
        return query(n-1);
    }
};

int main() {
    #ifdef  _SHIT
        freopen("../in" , "r" , stdin) ;
        freopen("../out" , "w" , stdout) ;
    #endif
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    vector<int> all;
    int q;
    cin >> q;
    vector<int>  qv(q);
    vector<char>  qt(q);
    for (int i = 0; i < q; i++) {
        cin >> qt[i] >> qv[i];
        all.push_back(qv[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    auto hs = [&](int val) {
        return lower_bound(all.begin(), all.end(), val) - all.begin();
    };
    Fenwick<int> fen;
    fen.init((int) all.size() + 5);
    for (int i = 0; i < q; i++) {
        char type = (char) qt[i];
        int val = hs(qv[i]) + 1;
        if (type == 'I') {
            int me = fen.range_query(val, val );
            assert(me >= 0 && me <= 1);
            if (me == 0)
                fen.update(val, 1);
        } else if (type == 'D') {
            int me = fen.range_query(val, val);
            assert(me >= 0 && me <= 1);
            if (me == 1)
                fen.update(val, -1);
        } else if (type == 'K') {
            int ans = fen.kth(qv[i]);
            if (ans == -1) {
                cout << "invalid" << endl;
            }else {
                cout << all[ans-1] <<endl;
            }
        } else {
            int ans = 0;
            if (val > 0)
                ans = fen.query(val - 1);
            cout << ans << endl;
        }
    }
    return 0;
}