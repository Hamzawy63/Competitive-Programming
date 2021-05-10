#include <bits/stdc++.h>

using namespace std;
const int mxN = 250000 + 4;
int a[mxN];
int hs[mxN];
const int BN = 500;
bool debug = false;

class Blk {
public:
    int st, end;

    void sort() {
        std::sort(hs + st, hs + end, [&](int i1, int i2) {
            return a[i1] < a[i2];
        });
        if (debug) {
            cerr << "Sorting the blocks starting at " << st << " and ending at " << end << endl;
            for (int i = st; i < end; i += 1) {
                cerr << a[hs[i]] << ' ';
            }
            cerr << endl;
        }
    }

    int how_many_greater_than(int value) {
        int lb = st, rb = end - 1;
        int ans = -1;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            if (a[hs[mb]] > value) {
                ans = mb;
                rb = mb - 1;
            } else {
                lb = mb + 1;
            }
        }
        if (ans == -1) return 0;
        else return (end - ans);
    }

    int how_many_less_than(int value) {
        int lb = st, rb = end - 1;
        int ans = -1;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            if (a[hs[mb]] < value) {
                ans = mb;
                lb = mb + 1;
            } else {
                rb = mb - 1;
            }
        }
        if (ans == -1) return 0;
        else return (ans - st + 1);
    }

    int local_inversions(int idx, int value) {
        assert(a[idx] == value);
        assert(idx >= st && idx < end);
        int ans = 0;
        for (int i = st; i < end; i++) {
            if (i < idx && a[i] > a[idx]) {
                ans += 1;
            } else if (i > idx && a[i] < a[idx]) {
                ans += 1;
            }
        }
        return ans;

    }

    void update(int idx, int new_val) {
        a[idx] = new_val;
        // clever sort
        int hashed_idx = -1;
        for (int i = st; i < end; i++) {
            if (hs[i] == idx) {
                hashed_idx = i;
                break;
            }
        }
        assert(hashed_idx != -1);
        int ptr = hashed_idx;
        while (ptr > st && (a[hs[ptr]] < a[hs[ptr - 1]])) {
            swap(hs[ptr], hs[ptr - 1]);
            ptr -= 1;
        }
        ptr = hashed_idx;
        while ((ptr + 1 < end) && (a[hs[ptr]] > a[hs[ptr + 1]])) {
            swap(hs[ptr], hs[ptr + 1]);
            ptr += 1;
        }
    }
};

const int N = 50000 + 1;
int fen[N];

int query(int idx) {
    int ans = 0;
    while (idx >= 0) {
        ans += fen[idx];
        idx = (idx & (idx + 1)) - 1;
    }
    return ans;
}

int suffix_query(int L) {
    int ans = 0;
    if (L >= N) return 0;
    ans = query(N - 1);
    if (L > 0)
        ans -= query(L - 1);
    return ans;
}

void update(int L, int delta) {
    while (L < N) {
        fen[L] += delta;
        L = L | (L + 1);
    }
}

long long int count_inversion(int n) {
    long long int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += suffix_query(a[i] + 1);
        update(a[i], 1);
    }
    return ans;
}

int get_blocks(int i) {
    return i / BN;
}


int main() {
#ifdef  _SHIT
    debug = true;
    freopen("../in", "r", stdin);
    freopen("../out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long int inversions = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hs[i] = i;
    }
    inversions = count_inversion(n);
    int q;
    cin >> q;

    int number_of_blocks = (n + BN - 1) / (BN);
    vector<Blk> blocks(number_of_blocks);
    for (int i = 0; i < number_of_blocks; i++) {
        blocks[i].st = BN * i;
        blocks[i].end = min(n, (BN) * (i + 1));
    }
    for (int i = 0; i < number_of_blocks; i++) {
        blocks[i].sort();
    }

    while (q--) {
        int idx_to_edit, new_val;
        cin >> idx_to_edit >> new_val;
        long long int change = 0;
        idx_to_edit -= 1;
        int old_value = a[idx_to_edit];
        int me = get_blocks(idx_to_edit);
        for (int i = 0; i < number_of_blocks; i++) {
            int subchage = 0;
            if (i < me) {
                subchage = blocks[i].how_many_greater_than(old_value);
            } else if (i > me) {
                subchage = blocks[i].how_many_less_than(old_value);
            }
            change += subchage;
        }
        change += blocks[me].local_inversions(idx_to_edit, old_value);

        inversions -= change;
        blocks[me].update(idx_to_edit, new_val); // a[idx_to_edit ] = new_val ;
        change = 0;
        for (int i = 0; i < number_of_blocks; i++) {
            int subchage = 0;
            if (i < me) {
                subchage = blocks[i].how_many_greater_than(new_val);
            } else if (i > me) {
                subchage = blocks[i].how_many_less_than(new_val);
            }
            change += subchage;
        }
        change += blocks[me].local_inversions(idx_to_edit, new_val);


        inversions += change;
        cout << inversions << '\n';


    }
    return 0;
}