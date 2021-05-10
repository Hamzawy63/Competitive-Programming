#include <bits/stdc++.h>

using namespace std;
// SPOJ : https://www.spoj.com/problems/INCSEQ/
// TAGS : DP - Fenwick
const int Mod = 5000000;

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
            ans %= Mod;
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
        ans %= Mod;
        ans += Mod;
        ans %= Mod;

        return ans;
    }

    type suffix_query(int L) {
        if (L >= n) return 0;

        assert(L >= 0);

        type ans = query(n - 1);
        if (L) ans -= query(L - 1);
        ans %= Mod;
        ans += Mod;
        ans %= Mod;
        return ans;
    }

    void update(int idx, type delta) {
        assert(initialized);
        assert(idx >= 0);
        assert(idx < n);
        while (idx < n) {
            fen[idx] += delta;
            fen[idx] %= Mod;
            idx = (idx | (idx + 1));
        }
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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<Fenwick<long long int> > fens(k + 1);
    for (int i = 1; i <= k; i++) {
        fens[i].init(100000 + 1);
    }

    long long total = 0 ;
    for (int i = 0; i < n; i++) {
//        int t;
//        cin >> t;
        long long int ans = 0;
        for (int j = 1; j <= k; j++) {
            // dp[i][k] = dp[i-1][k-1] + dp[i-2][k-1] + dp[i-2][k-1] + dp[i-3][k-1] ; ....
            if (j == 1) {
                fens[j].update(a[i], 1);
//                fprintf(stderr, "At fenwick[%d] we will update %d by 1 \n", j, a[i]);
                continue;
            } else if (a[i] > 0) {
                ans = fens[j - 1].query(a[i] - 1);
                fens[j].update(a[i], ans);
//                fprintf(stderr, "At fenwick[%d] we will update %d by %lld \n", j, a[i],ans );

            }
            if(j ==  k) {
                total += ans;
                total %=  Mod ;
            }
        }

    }
    cout << total << endl;
    return 0;
}