#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
vector<vector<pi>> g;

struct Query {
    char type;
    int val;
};

struct Fenwick {
    vi fen; // ONE BASED
    int n;

    Fenwick(int len) {
        this->n = len;
        fen.resize(len + 1, 0);
    }

    void update(int idx, int delta) {
        while (idx <= n) {
            fen[idx] += delta;
            idx += (idx) & (-idx);
        }
    }

    int sum(int l) {
        int res = 0;
        while (l > 0) {
            res += fen[l];
            l -= (l & -l);
        }
        return res;
    }

    int range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    string kth(int val) {
        if (val > sum(n))
            return "invalid";
        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int sss = sum(mid);
            if (sum(mid) >= val) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return to_string(ans);
    }
};

void solve() {
    vector<Query> queries;
    vector<int> vals;
    int qq;
    scanf("%d", &qq);
    for (int i = 1; i <= qq; i++) {
        char type;
        int val;
        scanf("\n%c%d", &type, &val);
        queries.pb({type, val});
        vals.pb(val);
    }
    sort(vals.begin(), vals.end());
    map<int, int> mp;
    map<int, int> decrypt;
    int cnt = 1, last = -2 * 1000000000;
    for (auto q : vals) {
        if (q != last) {
            mp[q] = cnt;
            last = q;
            decrypt[cnt++] = q;
        }
    }
    Fenwick fen(cnt);
    vi freq(cnt + 1, 0);
    for (auto q : queries) {
        char type = q.type;
        int val = q.val;
        int hashed = mp[val];
        if (type == 'I' && freq[hashed] == 0) {
            freq[hashed] = 1;
            fen.update(mp[val], 1);
        } else if (type == 'D' && freq[hashed] == 1) {
            freq[hashed] = 0;
            fen.update(hashed, -1);
        } else if (type == 'C') {
            cout << fen.sum(hashed - 1) << endl;
        } else if (type == 'K') {
            string kth = fen.kth(val);
            if (kth.compare("invalid") != 0) {
                cout << decrypt[stoi(kth)] << endl;
            } else
                cout << "invalid" << endl;
        }
    }

}

//#define _DEBUG

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}