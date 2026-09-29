
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid,
               int i, int j, int open, int close) {

        if (i >= m || j >= n) {
            return false;
        }

        if (grid[i][j] == '(') {
            open++;
        } else {
            close++;
        }

        if (close > open) {
            return false;
        }

        if (i == m - 1 && j == n - 1) {
            return open == close;
        }

        int balance = open - close;

        if (dp[i][j][balance] != -1) {
            return dp[i][j][balance];
        }

        bool right = solve(grid, i, j + 1, open, close);
        bool down = solve(grid, i + 1, j, open, close);

        return dp[i][j][balance] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();


        dp.assign(m, vector<vector<int>>(
            n, vector<int>(m + n + 1, -1)
        ));

        return solve(grid, 0, 0, 0, 0);
    }
};