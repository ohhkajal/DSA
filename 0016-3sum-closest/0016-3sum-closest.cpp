class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int max_diff = INT_MAX;
        int ressum = 0;

        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = n - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                int diff = abs(sum - target);

                if(max_diff > diff) {
                    max_diff = diff;
                    ressum = sum;
                }

                if(sum < target) {
                    l++;
                }
                else if(sum > target) {
                    r--;
                }
                else {
                    return sum;
                }
            }
        }

        return ressum;
    }
};