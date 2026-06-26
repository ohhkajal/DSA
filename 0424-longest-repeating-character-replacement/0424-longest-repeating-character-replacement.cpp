class Solution {

public:
    int find(vector<int>& a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++)
            maxc = max(maxc, a[i]);
        return maxc;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256, 0);
        int low = 0, high = 0;
        int res = 0;

        for (high = 0; high < n; high++) {
            f[s[high]]++;

            int maxcnt = find(f);

            while ((high - low + 1) - maxcnt > k) {
                f[s[low]]--;
                low++;

                maxcnt = find(f);
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};