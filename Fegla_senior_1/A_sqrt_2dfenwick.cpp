#include <bits/stdc++.h>

using namespace std;
bool debug = false;

// https://www.spoj.com/problems/SWAPS/en/

const int BLK = 500;
const int mxV = 50001;

int get_blk(int idx) {
    return idx / BLK;
}

const int N = 50001;

int query(int idx, vector<int> &fen) {
    int ans = 0;
    while (idx >= 0) {
        ans += fen[idx];
        idx = (idx & (idx + 1)) - 1;
    }
    return ans;
}

int suffix_query(int L, vector<int> &fen) {
    int ans = 0;
    if (L >= N) return 0;
    ans = query(N - 1, fen);
    if (L > 0)
        ans -= query(L - 1, fen);
    return ans;
}

void update(int L, int delta, vector<int> &fen) {
    while (L < N) {
        fen[L] += delta;
        L = L | (L + 1);
    }
}

vector<vector<int>> fens;

int main() {
#ifdef  _SHIT
    debug = false;
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> tmp(mxV);
    long long int inversions = 0; // count inversions;

    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
        inversions += suffix_query(a[i] + 1, tmp);
        update(a[i], 1, tmp);
    }
    fens.resize((n + BLK - 1) / BLK);
    for (int i = 0; i < (int) fens.size(); i++) {
        fens[i].resize(mxV);
    }
    for (int i = 0; i < n; i++) {
        int blk_idx = get_blk(i);
        update(a[i], 1, fens[blk_idx]);
//        fens[blk_idx].update(a[i], 1);
    }
    auto get_contribution = [&](int idx_to_edit) {
        int old_value = a[idx_to_edit];
        int me = get_blk(idx_to_edit);
        int contribution = 0;
        for (int i = 0; i < (int) fens.size(); i++) {
            int current_contribution = 0;
            if (i < me) { // how many bigger than me :(
                current_contribution = suffix_query(old_value + 1, fens[i]);
//                current_contribution = fens[i].suffix_query(old_value + 1);
            } else if (i > me) {
                current_contribution = query(old_value - 1, fens[i]);
            }
            if (debug) {
                cerr << "The contribution till the " << i << " block is " << contribution << endl;
            }
            contribution += current_contribution;
        }
        // recalcultate inversions for my block ;
        int st_idx = me * BLK;
        int end_idx = (me + 1) * BLK;
        end_idx = min(end_idx, n);
        for (int i = st_idx; i < end_idx; i++) {
            if (i < idx_to_edit && a[i] > a[idx_to_edit]) {
                contribution += 1;
            } else if (i > idx_to_edit && a[i] < a[idx_to_edit]) {
                contribution += 1;
            }
        }
        return contribution;
    };


    int q;
    scanf("%d", &q);
//    cin >> q;
    while (q--) {
        int idx_to_edit, new_value;
        scanf("%d%d", &idx_to_edit, &new_value);
//        cin >> idx_to_edit >> new_value;
        idx_to_edit -= 1;
        long long int contribution = get_contribution(idx_to_edit);

        if (debug) cerr << "Previous contribution is " << contribution << endl;

        int me = get_blk(idx_to_edit);

        // update the fenwick of the block
        inversions -= contribution;
        update(a[idx_to_edit], -1, fens[me]);
        update(new_value, 1, fens[me]);
//        fens[me].update(a[idx_to_edit], -1);
//        fens[me].update(new_value, 1);

        a[idx_to_edit] = new_value;
//        cerr << "contribution before " << contribution ;
        contribution = get_contribution(idx_to_edit);
//        cerr << "contribution after " << contribution ;
        if (debug) cerr << "Next contrubtion is " << contribution << endl;
        inversions += contribution;
        // increase the new inversions ;
//        cerr << "inversionsa are " <<  inversions << endl;
        printf("%lld\n", inversions);
//        cout << inversions << endl;

    }

    return 0;
}


