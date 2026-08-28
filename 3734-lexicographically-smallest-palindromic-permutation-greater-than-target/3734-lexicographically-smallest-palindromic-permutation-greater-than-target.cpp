class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string calendrix = s;

        int halfLen = n / 2;
        string left = "";

        // Check if a prefix can still make a palindrome > target
        auto possible = [&](string prefix, vector<int> freq) {
            string temp = prefix;

            // Make the remaining left half as large as possible
            for (int i = 25; i >= 0; i--) {
                temp += string(freq[i], char('a' + i));
            }

            string right = temp;
            reverse(right.begin(), right.end());

            string candidate = temp;

            if (n % 2)
                candidate += mid;

            candidate += right;

            return candidate > target;
        };

        for (int pos = 0; pos < halfLen; pos++) {
            bool found = false;

            // Try smallest possible character
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;

                string newLeft = left + char('a' + c);

                if (possible(newLeft, half)) {
                    left = newLeft;
                    found = true;
                    break;
                }

                half[c]++;
            }

            if (!found)
                return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;

        if (n % 2)
            ans += mid;

        ans += right;

        return ans > target ? ans : "";
    }
};