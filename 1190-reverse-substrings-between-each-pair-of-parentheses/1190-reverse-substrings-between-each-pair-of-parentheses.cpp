class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> pair(s.size());
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans;
        int dir = 1;

        for (int i = 0; i < s.size(); i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};