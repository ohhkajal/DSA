class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<vector<long long>> comb(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        function<long long(vector<int>&)> dfs = [&](vector<int>& arr) -> long long {
            if (arr.size() <= 2) return 1;

            vector<int> left, right;

            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] < arr[0])
                    left.push_back(arr[i]);
                else
                    right.push_back(arr[i]);
            }

            long long l = dfs(left);
            long long r = dfs(right);

            long long ways = comb[arr.size() - 1][left.size()];
            return ways * l % MOD * r % MOD;
        };

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};