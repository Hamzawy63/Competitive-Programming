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
#define mp make_pair
set<pi > top, bottom;
int median = -1;

void fix() {
    int sz1 = (int) bottom.size();
    int sz2 = (int) top.size();
    while ((sz1 != sz2) && (sz1 - sz2) != 1) {
        if (sz1 > sz2) {
            // botoom have a lot
            auto itr = bottom.rbegin();
            top.insert(*itr);
            bottom.erase(*itr);
            sz1--;
            sz2++;
        } else {
            auto itr = top.begin();
            bottom.insert(*itr);
            top.erase(*itr);
            sz1++;
            sz2--;
        }
    }
    median = bottom.rbegin()->ff;
}

void add(int x, int i) {
    if (median == -1) {
        median = x;
        bottom.insert(mp(x, i));
        return  ;
    }
    if (x < median) {
        bottom.insert(mp(x, i));
    } else {
        top.insert(mp(x, i));
    }
    fix();
}

void remove(int x) {
    if (x <= median) {
        bottom.erase(bottom.lower_bound(mp(x, -1)));
    } else {
        top.erase(top.lower_bound(mp(x, -1)));
    }
    fix();
}

void debug() {
//    for (auto itr : bottom) cerr << (itr).ff << space;
//    cerr << endl;
//    for (auto itr : top) cerr << (itr).ff << space;
//    cerr << endl << "End" << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        add(a[i], i);
    }
    debug();
    cout << median << space;
    for (int i = k; i < n; i++) {
        add(a[i], i);
        remove(a[i - k]);
        cout << median << space;
        debug();
    }
    cout << endl;
}