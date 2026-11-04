class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto balance = [&]() {
            while (left.size() > (x + 1) / 2) {
                int v = *left.rbegin();
                left.erase(prev(left.end()));
                sumL -= v;
                right.insert(v);
                sumR += v;
            }

            while (left.size() < (x + 1) / 2 && !right.empty()) {
                int v = *right.begin();
                right.erase(right.begin());
                sumR -= v;
                left.insert(v);
                sumL += v;
            }
        };

        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = left.find(v);

            if (it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                it = right.find(v);
                right.erase(it);
                sumR -= v;
            }
            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * (long long)left.size() - sumL
                 + sumR - median * (long long)right.size();
        };

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(k + 1,
                                     vector<long long>(n + 1, INF));

        dp[0][0] = 0;

        for (int j = 0; j <= k; j++) {
            for (int i = 0; i <= n; i++) {
                if (dp[j][i] == INF) continue;

                if (i < n)
                    dp[j][i + 1] = min(dp[j][i + 1], dp[j][i]);

                if (j < k && i + x <= n)
                    dp[j + 1][i + x] =
                        min(dp[j + 1][i + x], dp[j][i] + cost[i]);
            }
        }

        return dp[k][n];
    }
};