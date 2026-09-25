class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> st;

        function<set<string>(int&)> dfs = [&](int& i) {
            set<string> res;
            res.insert("");

            while (i < expression.size() && expression[i] != '}') {
                if (expression[i] == ',') {
                    i++;
                    continue;
                }

                set<string> cur;

                if (expression[i] == '{') {
                    i++;
                    cur = dfs(i);
                    i++;
                } else {
                    cur.insert(string(1, expression[i]));
                    i++;
                }

                set<string> temp;
                for (auto &a : res)
                    for (auto &b : cur)
                        temp.insert(a + b);

                res = temp;

                if (i < expression.size() && expression[i] == ',') {
                    set<string> next = dfs(i);
                    res.insert(next.begin(), next.end());
                    break;
                }
            }

            return res;
        };

        int i = 0;
        st = dfs(i);

        return vector<string>(st.begin(), st.end());
    }
};