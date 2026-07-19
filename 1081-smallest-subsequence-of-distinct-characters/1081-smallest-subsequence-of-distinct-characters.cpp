class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> last(26, 0);
        vector<bool> used(26, false);

        for(int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string res = "";

        for(int i = 0; i < s.size(); i++) {

            int x = s[i] - 'a';

            if(used[x])
                continue;

            while(!res.empty() &&
                  res.back() > s[i] &&
                  last[res.back() - 'a'] > i) {

                used[res.back() - 'a'] = false;
                res.pop_back();
            }

            res += s[i];
            used[x] = true;
        }

        return res;
    }
};