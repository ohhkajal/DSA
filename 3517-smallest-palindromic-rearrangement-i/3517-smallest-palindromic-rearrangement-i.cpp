class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        string half = "", mid = "";

        for (int i = 0; i < 26; i++) {
            half.append(cnt[i] / 2, 'a' + i);

            if (cnt[i] % 2)
                mid = char('a' + i);
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        return half + mid + rev;
    }
};