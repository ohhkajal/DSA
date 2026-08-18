class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        // Count in how many subarrays of size k
        // each number appears
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;

            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            for (int x : seen) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto &[num, cnt] : count) {
            if (cnt == 1)
                ans = max(ans, num);
        }

        return ans;
    }
};