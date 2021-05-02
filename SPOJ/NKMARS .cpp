#include <bits/stdc++.h>

#include <random>
#include <chrono>

using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
const double inf = 2e18;
#define EPS  0.0000000001
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

/**
 * This program is aimed to solve the area of rectangles Union of set of rectangles
 * the idea is using horizontal sweep inside vertical sweep
 * the input is in form of :
 *  n -->number of rectangles
 *  Xl Yl  Xt Yt
 *  bottom left points & top right points
 */
const int START = 0;
const int END = 1;

struct Event {
    int val;
    int idx;
    bool type;

    bool operator<(Event &o) {
        return this->val < o.val;
    }
};

const int maxN = 1e4 + 3;
pair<int, int> rect[maxN][2];

void solve() {
    int n;
    cin >> n;
    vector<Event> event_x, event_y;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rect[i][0] = {x1, y1};
        rect[i][1] = {x2, y2};

        event_x.push_back({x1, i, START});
        event_x.push_back({x2, i, END});

        event_y.push_back({y2, i, START});
        event_y.push_back({y1, i, END});
    }
    vector<bool> available(n, false);

    sort(event_x.begin(), event_x.end());
    sort(event_y.rbegin(), event_y.rend());
    ll ans = 0;
    int last_x = event_x[0].val;
    available[event_x[0].idx] = true;
    for (int i = 1; i < 2 * n; i++) {
        int dx = event_x[i].val - last_x;
        int cnt = 0; // count of the fucking points
        int top_y = -1;
        for (int j = 0; j < 2 * n; j++) {
            Event event = event_y[j];
            if (available[event.idx]) {
                if (event.type == START) {
                    cnt++;
                    top_y = max(top_y, event.val);
                } else {
                    cnt--;
                    if (cnt == 0) {
                        ans += dx * 1LL * (top_y - event.val);
                        top_y = -1;
                    }
                }
            }
        }
        available[event_x[i].idx] = event_x[i].type ^ 1;
        last_x = event_x[i].val;
    }
    cout << ans << '\n';


}

int main() {
    solve();
}