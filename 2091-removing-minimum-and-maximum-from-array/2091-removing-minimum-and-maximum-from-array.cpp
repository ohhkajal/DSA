class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        int left = min(mn, mx);
        int right = max(mn, mx);

        // 1. Remove both from front
        int front = right + 1;

        // 2. Remove both from back
        int back = n - left;

        // 3. Remove one from front and one from back
        int both = left + 1 + n - right;

        return min({front, back, both});
    }
};