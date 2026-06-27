class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int n = a.size();

        int maxEnding = a[0], minEnding = a[0];
        int maxSum = a[0], minSum = a[0];
        int total = a[0];

        for(int i = 1; i < n; i++) {

            total += a[i];

            maxEnding = max(a[i], maxEnding + a[i]);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(a[i], minEnding + a[i]);
            minSum = min(minSum, minEnding);
        }

        if(maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};