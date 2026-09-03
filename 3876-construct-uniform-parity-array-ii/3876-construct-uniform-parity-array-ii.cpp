class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;
        bool allEven = true;
        for (int x : nums1) {
            mn = min(mn, x);
            if (x % 2 != 0) allEven = false;
        }
        // If the minimum is odd, we can always make everything odd.
        if (mn % 2 != 0) return true;
        // If the minimum is even, it only works if every element is already even.
        return allEven;
    }
};