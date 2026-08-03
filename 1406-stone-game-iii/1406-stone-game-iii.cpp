class Solution {
public:
    int solve(vector<int>& stoneValue, int i, vector<int>& dp) {
        int n = stoneValue.size();

        if (i >= n)
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int best = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            best = max(best, take - solve(stoneValue, i + k + 1, dp));
        }

        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);

        int diff = solve(stoneValue, 0, dp);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};