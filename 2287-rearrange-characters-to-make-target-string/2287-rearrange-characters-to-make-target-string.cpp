class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        vector<int> fs(26, 0);
        vector<int> ft(26, 0);

        for(char ch : s)
            fs[ch - 'a']++;

        for(char ch : target)
            ft[ch - 'a']++;

        int res = INT_MAX;

        for(int i = 0; i < 26; i++) {

            if(ft[i] > 0) {

                int copies = fs[i] / ft[i];
                res = min(res, copies);
            }
        }

        return res;
    }
};