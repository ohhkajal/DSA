class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int ans = 0;

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' ||
                   c == 'o' || c == 'u';
        };

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i]))
                count++;

            if (i >= k && isVowel(s[i - k]))
                count--;

            if (i >= k - 1)
                ans = max(ans, count);
        }

        return ans;
    }
};