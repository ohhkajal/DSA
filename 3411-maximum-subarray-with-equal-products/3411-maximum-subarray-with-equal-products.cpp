class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long g = 0, lcm = 1;

            for (int j = i; j < n; j++) {
                long long x = nums[j];

                if (product > LLONG_MAX / x)
                    break;

                product *= x;
                g = gcd(g, x);

                long long d = gcd(lcm, x);

                if (lcm / d > LLONG_MAX / x)
                    break;

                lcm = (lcm / d) * x;

                if (product == g * lcm)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};