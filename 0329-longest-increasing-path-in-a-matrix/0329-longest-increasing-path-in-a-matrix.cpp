class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        if(dp[i][j] != -1)
            return dp[i][j];

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && x < n && y >= 0 && y < m &&
               matrix[x][y] > matrix[i][j]) {

                ans = max(ans, 1 + dfs(x, y, matrix, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int res = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                res = max(res, dfs(i, j, matrix, dp));
            }
        }

        return res;
    }
};