class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> open(n + 1, vector<int>(k + 1, 0));

        dp[1][0] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + open[i - 1][j]) % MOD;

                open[i][j] = open[i - 1][j];

                if (j > 0) {
                    open[i][j] = (open[i][j] + dp[i - 1][j - 1]) % MOD;
                    open[i][j] = (open[i][j] + open[i - 1][j - 1]) % MOD;
                }
            }
        }

        return (dp[n][k] + open[n][k]) % MOD;
    }
};