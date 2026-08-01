class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1 = 0;

        for (int i = 0; i < s.size(); i++) {
            char c1 = (i % 2 == 0) ? '0' : '1';
            char c2 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != c1)
                start0++;

            if (s[i] != c2)
                start1++;
        }

        return min(start0, start1);
    }
};