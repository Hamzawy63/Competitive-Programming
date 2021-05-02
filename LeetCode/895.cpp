#include <bits/stdc++.h>

using namespace std;

/**
    895. Maximum Frequency Stack
    31-3-2021  2:31 PM
    Runtime: 164 ms, faster than 83.88% of C++ online submissions for Maximum Frequency Stack.
    Memory Usage: 79.6 MB, less than 86.81% of C++ online submissions for Maximum Frequency Stack.
 */
class FreqStack {
public:
    unordered_map<int, int> mp;
    unordered_map<int, vector<int>> best;
    int ans;

    FreqStack() {
        ans = 0;
    }

    void push(int val) {
        mp[val] += 1;
        int cnt = mp[val];
        ans = max(ans, cnt);
        best[cnt].push_back(val);

    }

    int pop() {
        vector<int> &candidates = best[ans];
        int val = candidates.back();
        mp[val] -= 1;
        candidates.pop_back();
        if (candidates.empty()) {
            ans -= 1;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
