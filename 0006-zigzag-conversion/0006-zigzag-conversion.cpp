class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)
            return s;

        vector<string> rows(numRows);

        int curr = 0;
        bool down = true;

        for(int i = 0; i < s.size(); i++) {

            rows[curr] += s[i];

            if(curr == numRows - 1)
                down = false;
            else if(curr == 0)
                down = true;

            if(down)
                curr++;
            else
                curr--;
        }

        string res = "";

        for(int i = 0; i < numRows; i++)
            res += rows[i];

        return res;
    }
};