class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int n = s.size();
        unordered_map<char, int> f;
        int res = 0;

        for (int high = 0; high < n; high++) {
            f[s[high]]++;

            while (f[s[high]] > 1) {
                f[s[low]]--;
                low++;
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};