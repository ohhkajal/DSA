class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> seen;

        function<void(int, int, int, string)> dfs =
            [&](int i, int left, int right, string cur) {
                if (i == s.size()) {
                    if (left == right)
                        seen.insert(cur);
                    return;
                }

                if (s[i] == '(') {
                    dfs(i + 1, left, right, cur + s[i]);
                    dfs(i + 1, left, right, cur);
                }
                else if (s[i] == ')') {
                    if (right < left)
                        dfs(i + 1, left, right + 1, cur + s[i]);

                    dfs(i + 1, left, right, cur);
                }
                else {
                    dfs(i + 1, left, right, cur + s[i]);
                }
            };

        int open = 0, close = 0;

        for (char c : s) {
            if (c == '(') open++;
            else if (c == ')') {
                if (open > 0) open--;
                else close++;
            }
        }

        function<void(int, int, int, int, string)> solve =
            [&](int i, int lrem, int rrem, int bal, string cur) {
                if (i == s.size()) {
                    if (lrem == 0 && rrem == 0 && bal == 0)
                        seen.insert(cur);
                    return;
                }

                if (s[i] == '(') {
                    if (lrem > 0)
                        solve(i + 1, lrem - 1, rrem, bal, cur);

                    solve(i + 1, lrem, rrem, bal + 1, cur + '(');
                }
                else if (s[i] == ')') {
                    if (rrem > 0)
                        solve(i + 1, lrem, rrem - 1, bal, cur);

                    if (bal > 0)
                        solve(i + 1, lrem, rrem, bal - 1, cur + ')');
                }
                else {
                    solve(i + 1, lrem, rrem, bal, cur + s[i]);
                }
            };

        seen.clear();
        solve(0, open, close, 0, "");

        for (auto &x : seen)
            ans.push_back(x);

        return ans;
    }
};