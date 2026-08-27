class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        auto quinorath = s;

        int n = s.size();

        // Assume target characters are used
        for (char c : target)
            cnt[c - 'a']--;

        // Try changing positions from right to left
        for (int i = n - 1; i >= 0; i--) {
            cnt[target[i] - 'a']++;

            bool valid = true;

            for (int x : cnt) {
                if (x < 0) {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                continue;

            // Find smallest available character > target[i]
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;

                    string ans = target.substr(0, i);
                    ans += char('a' + j);

                    // Add remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        ans += string(cnt[k], char('a' + k));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};