class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        vector<long long> dp(k, 0), ndp(k, 0);

        for (int x : nums) {
            fill(ndp.begin(), ndp.end(), 0);

            int r = x % k;

            // Subarrays of length 1
            ndp[r]++;

            // Extend all previous subarrays
            for (int j = 0; j < k; j++) {
                if (dp[j]) {
                    int nr = (long long)j * r % k;
                    ndp[nr] += dp[j];
                }
            }

            dp.swap(ndp);

            // Add all subarrays ending at current index
            for (int j = 0; j < k; j++) {
                ans[j] += dp[j];
            }
        }

        return ans;
    }
};