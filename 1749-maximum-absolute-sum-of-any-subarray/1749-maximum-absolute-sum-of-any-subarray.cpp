class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int n = a.size();

        int maxEnding = a[0];
        int minEnding = a[0];

        int maxSum = a[0];
        int minSum = a[0];

        for (int i = 1; i < n; i++) {

            maxEnding = max(a[i], maxEnding + a[i]);
            minEnding = min(a[i], minEnding + a[i]);

            maxSum = max(maxSum, maxEnding);
            minSum = min(minSum, minEnding);
        }

        return max(maxSum, abs(minSum));
    }
};