#include <bits/stdc++.h>
 
#define space " "
using namespace std;
typedef long long int ll;
 
struct TrieNode {
    int end;
    vector<TrieNode *> nxt;
 
    TrieNode() {
        end = false;
        nxt.resize(2, nullptr);
    }
};
 
void insert(TrieNode *root, ll num, int idx) {
    if (idx == -1) {
        root->end = true;
        return; // t2rebn
    }
    int bit = (num & (1LL << idx)) != 0;
    assert(bit < 2);
    if (root->nxt[bit] == nullptr) {
        root->nxt[bit] = new TrieNode();
    }
    return insert(root->nxt[bit], num, idx - 1);
}
 
ll get_best(TrieNode *root, ll num, int idx) {
    if (idx == -1) {
        return 0;
    }
    int bit = (num & (1LL << idx)) != 0;
    assert(bit < 2);
    if (root->nxt[1 ^ bit] != nullptr) {
        return (1LL << idx) + get_best(root->nxt[1 ^ bit], num, idx - 1);
    } else {
        return get_best(root->nxt[bit], num, idx - 1);
    }
 
}
 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll prefix = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix = a[i] ^ prefix;
    }
    TrieNode *root = new TrieNode();
    ll right = 0;
    ll ans = prefix ^right;
    for (int i = n - 1; i >= 0; i--) {
        // remove a[i] from the prefix
        prefix ^= a[i];
        ans = max(ans, prefix);
        // add a[i] to the trie
        right ^= a[i];
 
        insert(root, right, 60);
        // check the best answer for the current prefix using the trie
        ll best = get_best(root, prefix, 60);
//        cerr << prefix << space << right << space << best << endl;
        ans = max(best, ans);
    }
 
    cout << ans << endl;
    return 0;
}
