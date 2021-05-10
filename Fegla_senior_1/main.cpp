#include <iostream>

int main() {
   for(char c = 'A' ; c <= 'Z' ; c++){
        printf("add_executable(%c %c.cpp)\n" , c , c  )  ;
   }
}
template<class type>
class Fenwick {
    // zero based fenwick tree
    int n;
    unordered_map<type, int> fen;
    bool initialized; // to make sure the methods are used after calling init .
    bool is_mod = true;

public:
    Fenwick() {
        initialized = false;
    }

    void init(int n) {
        initialized = true;
        this->n = n;
    }

    type query(int L) {
//        assert(initialized);
        type ans = 0;
        while (L >= 0) {
            ans += fen[L];
            L = (L & (L + 1)) - 1;
        }
        return ans;
    }

    type range_query(int L, int R) {
//        assert(initialized);
//        assert(R < n);
//        assert(L >= 0);
        type ans = query(R);
        if (L) ans -= query(L - 1);


        return ans;
    }

    type suffix_query(int L) {
        if (L >= n) return 0;
//        assert(L >= 0);
        type ans = query(n - 1);
        if (L) ans -= query(L - 1);
        return ans;
    }

    void update(int idx, type delta) {
//        assert(initialized);
//        assert(idx >= 0);
//        assert(idx < n);
        while (idx < n) {
            fen[idx] += delta;
            idx = (idx | (idx + 1));
        }
    }
};
