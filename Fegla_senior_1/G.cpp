#include <bits/stdc++.h>

using namespace std;

// sort by R
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
            ans ^= fen[L];
            L = (L & (L + 1)) - 1;
        }
        return ans;
    }

    type range_query(int L, int R) {
        assert(initialized);
        assert(R < n);
        assert(L >= 0);
        type ans = query(R);
        if (L) ans ^= query(L - 1);


        return ans;
    }

    type suffix_query(int L) {
        if (L >= n) return 0;

        assert(L >= 0);

        type ans = query(n - 1);
        if (L) ans ^= query(L - 1);
        return ans;
    }

    void update(int idx, type delta) {
        assert(initialized);
        assert(idx >= 0);
        assert(idx < n);
        while (idx < n) {
            fen[idx] ^= delta;
            idx = (idx | (idx + 1));
        }
    }
};

const int mxN = 1000000 + 3;
int a[mxN];
map<int, int> last;
int idx[mxN], L[mxN], R[mxN], ans[mxN] , pre[mxN];

int main() {
    #ifdef  _SHIT
        freopen("../in" , "r" , stdin) ;
        freopen("../out" , "w" , stdout) ;
    #endif
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i] ;
        if(i) pre[i] ^= pre[i-1] ;
    }
    auto prefix=[&](int L , int R ) {
        int ans = pre[R] ;
        if(L) ans^= pre[L-1] ;
        return ans;
    };
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i];
        L[i] -= 1;
        R[i] -= 1;
        idx[i] = i;
    }
    sort(idx, idx + m, [&](int a, int b) {
        return R[a] < R[b];
    });
    int query_ptr = 0;
    Fenwick<int> fen;
    fen.init(n + 4);
    for (int i = 0; i < n; i++) {
        if (!last.count(a[i])) {
            fen.update(i, a[i]);
        } else {
            int last_occur = last[a[i]];
            fen.update(last_occur, a[i]);
            fen.update(i, a[i]);
        }
        last[a[i]] = i;
//        fprintf(stderr , "after putting the %d th element %d\n" , i , a[i]) ;
//        for(int j=0;j<n;j++){
//            fprintf(stderr , "fen[%d] = %d " , j,fen.query(j) ) ;
//        }
//        fprintf(stderr , "\n") ;
        while (query_ptr < m && R[idx[query_ptr]] <= i) {
            int res = 0;
            res = fen.query(R[idx[query_ptr]]);
            if(L[idx[query_ptr]] > 0 ) {
                res ^= fen.query(L[idx[query_ptr]] -1 ) ;
            }
            // res is the xor of distinct elements in the range [L,R]
//            fprintf(stderr , "L = %d , R = %d  distinct xor = %d\n" , L[idx[query_ptr]] , R[idx[query_ptr]] , res) ;
            res = res ^ prefix(L[idx[query_ptr]] , R[idx[query_ptr]]) ;

//           fprintf(stderr , "L = %d , R = %d , Xor = %d\n", L[idx[query_ptr]] , R[idx[query_ptr]] , res ) ;
            ans[idx[query_ptr]] = res ;
            query_ptr += 1;

        }

    }
    for(int i=0;i<m;i++){
        cout << ans[i] << '\n' ;
    }


    return 0;
}