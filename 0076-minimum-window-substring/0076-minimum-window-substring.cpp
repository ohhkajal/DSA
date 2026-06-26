class Solution {
public:
    bool check(vector<int>& have, vector<int>& need) {
        for (int i = 0; i < 126; i++) {
            if (have[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> have(126, 0), need(126, 0);

        for (char c : t)
            need[c]++;

        int low = 0, start = 0, minLen = INT_MAX;

        for (int high = 0; high < s.size(); high++) {
            have[s[high]]++;

            while (check(have, need)) {
                int len = high - low + 1;

                if (len < minLen) {
                    minLen = len;
                    start = low;
                }

                have[s[low]]--;
                low++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};