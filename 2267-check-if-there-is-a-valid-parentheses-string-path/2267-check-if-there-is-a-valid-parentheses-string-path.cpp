class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if ((m + n) % 2 == 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n, -1))
        );

        function<bool(int, int, int)> dfs = [&](int r, int c, int bal) -> bool {
            if (r >= m || c >= n) return false;

            bal += (grid[r][c] == '(' ? 1 : -1);

            if (bal < 0 || bal > m + n - r - c - 1)
                return false;

            if (r == m - 1 && c == n - 1)
                return bal == 0;

            int &res = dp[r][c][bal];
            if (res != -1) return res == 1;

            res = (dfs(r + 1, c, bal) || dfs(r, c + 1, bal));
            return res == 1;
        };

        return dfs(0, 0, 0);
    }
};