#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second

struct Path {
    string s;
    vector<ll> val;
};

int maxN = 25;
vector<ar<int, 3>> a(maxN);
vector<Path> all_paths;
int n;
string path = "";
vector<ll> value = {0, 0, 0};
const vector<string> pc = {"MW", "LW", "LM"};

void generate_all(int L, int R) {
    if (L > R) {
        all_paths.push_back({path, value});
        return;
    }
    for (int i = 0; i < 3; i++) {
        path += pc[i];
        value[(i + 1) % 3] += a[L][(i + 1) % 3];
        value[(i + 2) % 3] += a[L][(i + 2) % 3];
        generate_all(L + 1, R);
        path.pop_back();
        path.pop_back();
        value[(i + 1) % 3] -= a[L][(i + 1) % 3];
        value[(i + 2) % 3] -= a[L][(i + 2) % 3];

    }
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, m, w;
        cin >> l >> m >> w;
        a[i][0] = l;
        a[i][1] = m;
        a[i][2] = w;
    }
    generate_all(0, n / 2 - 1);
    generate_all(n / 2, n - 1);
    // pow(3 , n/2 )
    int len = (int) pow(3, n / 2);
    map<pair<ll, ll>, int> mp;
    for (int i = 0; i < len; i++) {
        ll first = all_paths[i].val[0] - all_paths[i].val[1];
        ll second = all_paths[i].val[1] - all_paths[i].val[2];
        if (mp.count(make_pair(first, second))) {
            cout << "WhoW" << endl;
            auto &itr = mp[make_pair(first, second)];
            cout << all_paths[itr].val[0] << space << all_paths[i].val[0] << endl;
            if (all_paths[itr].val[0] < all_paths[i].val[0]) {
                cout << "catch up " << endl;
                itr = i;
            }
        } else
            mp[make_pair(first, second)] = i;
    }
    ll best_ans = LONG_LONG_MIN;
    pair<int, int> idx_res = {-1, -1};
    for (int j = len + 1; j < (int) all_paths.size(); ++j) {
        ll first = all_paths[j].val[0] - all_paths[j].val[1];
        ll second = all_paths[j].val[1] - all_paths[j].val[2];
        if (mp.count(make_pair(-first, -second))) {
            ll aa = mp[make_pair(-first, -second)];
            if (all_paths[aa].val[0] + all_paths[j].val[0] > best_ans) {
                best_ans = all_paths[aa].val[0] + all_paths[j].val[0];
                idx_res = {mp[make_pair(-first, -second)], j};
            }
        }
    }
    if (idx_res.ff == -1) {
        cout << "Impossible" << endl;
    } else {
        // cout << best_ans << endl;
        string res = "";
        res += all_paths[idx_res.ff].s;
        res += all_paths[idx_res.ss].s;
        for (int i = 0; i < (int) res.size(); i++) {
            cout << res[i];
            if (i % 2 == 1) cout << endl;
        }

    }

}

int main() {
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}