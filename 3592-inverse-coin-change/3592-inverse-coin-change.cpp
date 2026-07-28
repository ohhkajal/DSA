class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;

        vector<int> ans;

        for (int coin = 1; coin <= n; coin++) {
            if (dp[coin] > numWays[coin - 1])
                return {};

            if (dp[coin] < numWays[coin - 1]) {
                ans.push_back(coin);

                for (int j = coin; j <= n; j++)
                    dp[j] += dp[j - coin];
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] != numWays[i - 1])
                return {};
        }

        return ans;
    }
};