#include <bits/stdc++.h>

using namespace std;
const int mxN = 100000;
const int mxQ = 50000;

int a[mxN + 4];
int idx[mxN + 3];
const int BLK = 300;

class Block {
public:
    int L, R;

    void sort() {
        ::sort(idx + L, idx + R, [&](int f, int s) {
            return a[f] < a[s];
        });
    }

    void edit(int ii, int value) {
        // ii is the index in the original array
        a[ii] = value;
//        sort();
//        return;
        int my_idx = -1;
        for (int i = L; i < R; i++) {
            if (idx[i] == ii) {
                my_idx = i;
            }
        }
        int ptr = my_idx;
        bool ok = false;
        while ((my_idx > L) && (a[idx[my_idx]] < a[idx[my_idx - 1]])) {
            ok = true;
            swap(idx[my_idx], idx[my_idx - 1]);
            my_idx -= 1;
        }
        if (!ok) {
            my_idx = ptr;
            while ((my_idx + 1 < R) && (a[idx[my_idx]] > a[idx[my_idx + 1]])) {
                swap(idx[my_idx], idx[my_idx + 1]);
                my_idx += 1;
            }
        }
        for (int i = L + 1; i < R; i++) {
            if (a[idx[i]] < a[idx[i - 1]]) {
                assert(false);
            }
        }

    }

    int how_many_less_than_or_equal(int x) {
        int lb = L, rb = R - 1;
        int ans = -1 + L;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            if (a[idx[mb]] <= x) {
                ans = mb;
                lb = mb + 1;
            } else {
                rb = mb - 1;
            }
        }
        return ans - L + 1;
    }

    int brute_force(int st, int end, int x) {
        assert(st <= end && st >= L && end <= R);
        int ans = 0;
        for (int i = st; i < end; i++) {
            if (a[i] <= x) ans += 1;
        }
        return ans;
    }

    void debug() {
//        for (int i = L; i < R; i++) {
//            cout << a[idx[i]] << ' ';
//        }
//        cout << endl;
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

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
        cin >> a[i];
    }
    vector<Block> blocks((n + BLK - 1) / BLK);
    for (int i = 0; i < (int) blocks.size(); i++) {
        blocks[i].L = i * BLK;
        blocks[i].R = min((i + 1) * BLK, n);
        blocks[i].sort();
        blocks[i].debug();
    }

    auto get_block = [&](int i) {
        return i / BLK;
    };
    while (q--) {
        char T;
        cin >> T;
        if (T == 'M') {
            int i, new_val;
            cin >> i >> new_val;
            i -= 1;
            int me = get_block(i);
            blocks[me].edit(i, new_val);
        } else {
            int P, Q, X;
            cin >> P >> Q >> X;
            P -= 1;
            Q -= 1;
            int me1 = get_block(P);
            int me2 = get_block(Q);
            int ans = 0;
            for (int i = me1 + 1; i < me2; i++) {
                ans += blocks[i].how_many_less_than_or_equal(X);
            }
            ans += blocks[me1].brute_force(P, min(Q + 1, (me1 + 1) * BLK), X);
            if (me1 != me2)
                ans += blocks[me2].brute_force(max(P, (me2) * BLK), Q + 1, X);
            cout << ans << endl;

        }
    }


    return 0;
}