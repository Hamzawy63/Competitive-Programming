#include <bits/stdc++.h>

using namespace std;
/*
 @author Hamza Hassan Mohammed 
 31-3-2021 
 Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Number of Flips to Convert Binary Matrix to Zero Matrix.
 Memory Usage: 6.6 MB, less than 97.97% of C++ online submissions for Minimum Number of Flips to Convert Binary Matrix to Zero Matrix.

 */
class Solution {
public:
    int minFlips(vector<vector<int>> &mat) {
        int n = (int) mat.size();
        int m = (int) mat[0].size();
        return solve(mat, 0, 0);
    }

    vector<int> dx = {0, -1, 1, 0, 0};
    vector<int> dy = {0, 0, 0, -1, 1};

    int solve(vector<vector<int>> &mat, int r, int c) {
        int n = (int) mat.size();
        int m = (int) mat[0].size();
        if (r == n && c == 0) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cnt += mat[i][j];
                }
            }
            if (cnt == 0) {
                return 0;
            } else
                return 1000;
        }
        int mn = INT_MAX;
        int nr = r, nc = c + 1;
        if (nc == m) {
            nr += 1;
            nc = 0;
        }
        mn = solve(mat, nr, nc);

        for (int i = 0; i < 5; i++) {
            int ii = r + dx[i];
            int jj = c + dy[i];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
                mat[ii][jj] = (1 ^ mat[ii][jj]);
            }
        }
        mn = min(mn, 1 + solve(mat, nr, nc));
        for (int i = 0; i < 5; i++) {
            int ii = r + dx[i];
            int jj = c + dy[i];
            if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
                mat[ii][jj] = (1 ^ mat[ii][jj]);
                /*cnt += 1;*/
            }
        }

        return mn;

    }
};

int main() {
    vector<vector<int>> mat = {{1, 1, 1},
                               {1, 0, 1},
                               {0, 0, 0}
    };

    Solution s;
    int res = s.minFlips(mat);
    cout << res << endl;

}