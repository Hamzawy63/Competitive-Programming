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

int main() {
    #ifdef  _SHIT
        freopen("../in" , "r" , stdin) ;
        freopen("../out" , "w" , stdout) ;
    #endif
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> aa(n);
        for (int i = 0; i < n; i++) {
            cin >> aa[i];
        }
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        vector<int> a;
        for (int i = 0; i < n; i++) {
            a.push_back(mp[aa[i]]);
        }
        for(auto v : a ) {
            cerr << v << ' ' ;
        }
        cerr << endl;
        Fenwick<int> fen;
        fen.init((int) a.size() + 5);
        long long int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fen.suffix_query(a[i] + 1);
            fen.update(a[i], 1);
        }
        cout << ans << endl;

    }
    return 0;
}