class Solution {
public:
    int solve(int i, int M, vector<int>& suffix, vector<vector<int>>& dp) {
        int n = suffix.size() - 1;

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {
            int taken = suffix[i] - suffix[i + x];

            int opponent = solve(i + x, max(M, x), suffix, dp);

            ans = max(ans, taken + suffix[i + x] - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, suffix, dp);
    }
};